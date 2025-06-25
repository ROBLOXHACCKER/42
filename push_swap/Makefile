# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iinclude

SRC_DIR     = src
INCLUDE_DIR = include
OBJ_DIR     = obj
UTILS_DIR   = $(INCLUDE_DIR)/take_arg
MOVEMENT_DIR = $(INCLUDE_DIR)/movement

SRC         = $(SRC_DIR)/main.c \
              $(SRC_DIR)/sort.c \
              $(SRC_DIR)/counter.c \
              $(UTILS_DIR)/check_error.c \
              $(UTILS_DIR)/init_args.c \
              $(UTILS_DIR)/utils_arg.c \
              $(UTILS_DIR)/utils_list.c \
              $(MOVEMENT_DIR)/swap.c \
              $(MOVEMENT_DIR)/push.c \
              $(MOVEMENT_DIR)/rotate.c \
              $(MOVEMENT_DIR)/reverse_r.c

OBJ         = $(SRC:%.c=$(OBJ_DIR)/%.o)

# **************************************************************************** #
#                                 RULES                                        #
# **************************************************************************** #

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re