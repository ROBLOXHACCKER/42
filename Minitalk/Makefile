# Nome del programma
NAME = minitalk

# Compilatore e flag
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Cartelle
SRC_DIR = src
INCLUDE_DIR = include/mini-fun
LIBFT_DIR = include/ft_printf/libft
PRINTF_DIR = include/ft_printf

# File sorgenti
SRCS_CLIENT = $(SRC_DIR)/client.c
SRCS_SERVER = $(SRC_DIR)/server.c

# File oggetto
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

# Librerie
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Comandi per compilare le librerie
LIBFT_RULE = make -C $(LIBFT_DIR)
PRINTF_RULE = make -C $(PRINTF_DIR)

# Target principale
all: $(LIBFT) $(PRINTF) client server

# Compila la libft
$(LIBFT):
	$(LIBFT_RULE)

# Compila ft_printf
$(PRINTF):
	$(PRINTF_RULE)

# Compila il client
client: $(OBJS_CLIENT) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o client

# Compila il server
server: $(OBJS_SERVER) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o server

# Regola per pulire i file oggetto
clean:
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)
	$(LIBFT_RULE) clean
	$(PRINTF_RULE) clean

# Regola per pulire tutto
fclean: clean
	rm -f client server
	$(LIBFT_RULE) fclean
	$(PRINTF_RULE) fclean

# Regola per ricompilare tutto
re: fclean all

