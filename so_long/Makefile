# **************************************************************************** #
#                              MAKEFILE PER so_long                            #
# **************************************************************************** #

NAME = so_long

CC = clang
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -framework OpenGL -framework AppKit
MLX_DIR = include/minilibx_opengl_20191021
MLX_LIB = $(MLX_DIR)/libmlx.a

INCLUDES = -Iinclude -I$(MLX_DIR)

SRC = src/main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) $(INCLUDES) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

