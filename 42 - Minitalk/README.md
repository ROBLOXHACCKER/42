# 42 > MiniTalk

## Introduzione
Questo progetto permette la comunicazione tra due processi, **client** e **server**, utilizzando come "lingua" i segnali UNIX: **SIGUSR1** e **SIGUSR2**.

### Concetti chiave da risolvere:
1. **Mittente:** come convertire un messaggio in segnali UNIX.
2. **Mittente:** come mandare i segnali al destinatario.
3. **Destinatario:** come catturare i segnali.
4. **Destinatario:** come ricostruire il messaggio.

---

## Segnali UNIX
Un segnale è un impulso asincrono trasmesso da un processo a un altro. Nei sistemi UNIX, i segnali sono uno strumento standard per la comunicazione tra processi.

- **Invio segnali:** tramite la funzione `kill()` o `signal()`
- **Ricezione e gestione:** tramite la struttura `sigaction`

---

## SIGACTION
La gestione più affidabile dei segnali avviene tramite la struttura C `sigaction`, che permette di:
- Decidere quale funzione chiamare per gestire il segnale
- Bloccare determinati segnali durante la gestione
- Scegliere tra `sa_handler` e `sa_sigaction` per la gestione avanzata

---

## Da CHAR a SIGNAL (ASCII → BINARY → SIGNAL)
- Ogni carattere è rappresentato da un codice ASCII (un intero tra 32 e 126 per i caratteri stampabili).
- Questo numero viene convertito in binario (8 bit).
- Ogni bit viene inviato come segnale UNIX: **SIGUSR1** per 0, **SIGUSR2** per 1.
- Il destinatario ricostruisce il carattere ricevendo la sequenza di segnali e ricostruendo il valore ASCII.
- Le operazioni bitwise (`>>`, `&`, ecc.) permettono di estrarre ogni singolo bit.

---

## Funzioni principali

### `void send_message(pid_t server_pid, const char *msg);`
Invia un intero messaggio (stringa) al server, carattere per carattere, usando la funzione `send_char` per convertire ogni carattere in una sequenza di segnali UNIX.

**Come funziona:**
- Scorre la stringa `msg` carattere per carattere.
- Per ogni carattere, chiama `send_char`, che invia i singoli bit tramite segnali.
- Alla fine, invia anche il carattere di fine stringa (`'\0'`) per segnalare al server la fine del messaggio.

---

### `void send_char(pid_t server_pid, char c);`
Invia un singolo carattere al server, bit per bit, usando i segnali **SIGUSR1** e **SIGUSR2**.

**Come funziona:**
- Inizializza `count_bit` a 8 (un carattere = 8 bit).
- Ciclo che si ripete 8 volte, una per ogni bit del carattere.
- Ad ogni iterazione:
  - Calcola il valore del bit corrente: `(c >> count_bit) & 1`.
  - Se il bit è 1, invia **SIGUSR2**; se è 0, invia **SIGUSR1**.
  - Se `kill` fallisce, stampa un errore ed esce.
  - Dopo ogni segnale, aspetta 200 microsecondi con `usleep(200)`.
- Ogni carattere viene così "spezzato" in 8 segnali.

---

### `void signal_handler(int signo, siginfo_t *info, void *context);` (server)
Ricostruisce i caratteri ricevuti dal client, bit per bit, e li stampa a schermo.

**Come funziona:**
- Usa due variabili statiche:
  - `c` per accumulare i bit ricevuti e ricostruire il carattere.
  - `bit_count` per contare quanti bit sono stati ricevuti.
- Ad ogni segnale ricevuto:
  - Sposta `c` di un bit a sinistra (`c <<= 1`).
  - Se il segnale è **SIGUSR2**, imposta il bit meno significativo a 1 (`c |= 1`).
  - Incrementa `bit_count`.
- Quando sono stati ricevuti 8 bit:
  - Se il carattere ricostruito è `'\0'`, stampa un newline (fine messaggio).
  - Altrimenti, stampa il carattere.
  - Resetta `c` e `bit_count` per il prossimo carattere.

---

## Esempio di flusso
1. Il client prende il messaggio da inviare.
2. Converte ogni carattere in 8 bit e invia i segnali corrispondenti al server.
3. Il server riceve i segnali, ricostruisce i caratteri e stampa il messaggio.

---

## Note finali
- Tutto il progetto è conforme alle norme 42 (Norminette).
- Tutti i controlli sugli input e sulla memoria sono stati effettuati.
- Il Makefile è silenzioso e stampa solo "PROGETTO COMPILATO".

---

**Per domande o approfondimenti, consulta i commenti nel codice o chiedi durante l'orale!**
