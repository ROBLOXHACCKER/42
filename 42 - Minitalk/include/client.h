/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:32:00 by hurasmi           #+#    #+#             */
/*   Updated: 2025/07/01 12:41:08 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
#include <sys/types.h>
# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/libft/libft.h"

void	send_message(pid_t server_pid, const char *msg);
void	send_char(pid_t server_pid, char c);
int		check_input(int argc, char **argv);

#endif