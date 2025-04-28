NAME = so_long

CC = clang
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -framework OpenGL -framework AppKit

# Include and path settings
INCLUDES = -Iinclude -Iinclude/minilibx_opengl_20191021
MLX_LIB = include/minilibx_opengl_20191021/libmlx.a

SRC_DIR = src
INC_DIR = include

# Collect all .c files under src and include
SRC = $(SRC_DIR)/main.c \
      $(INC_DIR)/graphic_manager.c \
      $(INC_DIR)/key_menager.c \
      $(INC_DIR)/map_menager.c \
      $(INC_DIR)/system_manager.c

OBJ = $(SRC:.c=.o)

# Default target
all: $(NAME)

# Link the object files into the final binary
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) $(INCLUDES) $(MLX_FLAGS) -o $(NAME)

# Rule for compiling .c to .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJ)

# Clean everything including the binary
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re