# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 10:00:00 by hurasmi           #+#    #+#              #
#    Updated: 2025/06/25 09:54:55 by hurasmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nomi degli eseguibili
NAME_SERVER = server
NAME_CLIENT = client

# Sorgenti
SRC_SERVER = src/server.c src/utils/printf_opt.c src/utils/utils_server/utils_server.c
SRC_CLIENT = src/client.c src/utils/printf_opt.c src/utils/utils_client/utils_client.c

# Directory e oggetti
OBJ_DIR = obj
OBJS_SERVER = $(SRC_SERVER:src/%.c=$(OBJ_DIR)/%.o)
OBJS_CLIENT = $(SRC_CLIENT:src/%.c=$(OBJ_DIR)/%.o)

# Compilatore e flag
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilibs/ft_printf/includes

# Libreria ft_printf
FT_PRINTF_DIR = libs/ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

# Regole principali
all: $(FT_PRINTF_LIB) $(NAME_SERVER) $(NAME_CLIENT)
	@echo "\n\t42 - Minitalk\n\nCompilato [x]\n\n1 - Avviare './server'\n2 - Avviare './client <PID_server> <MSG>'\n"

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(FT_PRINTF_LIB):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME_SERVER): $(OBJS_SERVER)
	@$(CC) $(CFLAGS) $(OBJS_SERVER) $(FT_PRINTF_LIB) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) $(FT_PRINTF_LIB) -o $(NAME_CLIENT)

# Pulizia
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
