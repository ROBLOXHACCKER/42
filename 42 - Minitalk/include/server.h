/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 06:30:32 by hurasmi           #+#    #+#             */
/*   Updated: 2025/07/01 11:35:54 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/libft/libft.h"

void	signal_handler(int sig, siginfo_t *info, void *context);
void	print_server_banner(pid_t pid);

#endif