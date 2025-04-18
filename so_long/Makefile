NAME = so_long

CC = clang
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -framework OpenGL -framework AppKit

# Include e path
INCLUDES = -Iinclude -Iinclude/minilibx_opengl_20191021
MLX_LIB = include/minilibx_opengl_20191021/libmlx.a

SRC_DIR = src
INC_DIR = include

SRC = $(SRC_DIR)/main.c \
	  $(INC_DIR)/system_manager.c \
	  $(INC_DIR)/graphic_manager.c \
	  $(INC_DIR)/key_menager.c

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