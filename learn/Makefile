# Nome dell'eseguibile
NAME = program

# Compilatore e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# File sorgenti
SRCS = src/main.c src/function.c

# File oggetto (cambia .c in .o)
OBJS = $(SRCS:.c=.o)

# Regola principale
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Pulizia dei file oggetto
clean:
	rm -f $(OBJS)

# Pulizia completa
fclean: clean
	rm -f $(NAME)

# Rebuild completo
re: fclean all

.PHONY: all clean fclean re