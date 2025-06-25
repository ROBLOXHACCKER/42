/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:00:00 by hurasmi           #+#    #+#             */
/*   Updated: 2025/06/25 10:01:36 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/utils.h"
#include <signal.h>

void	print_server_banner(pid_t pid)
{
	ft_printf("\n\033[33mSERVER\033[0m\n\n");
	ft_printf("[#]    - Server PID: \033[32m%d\033[0m\n\n\n", pid);
	print_info("- Waiting for messages...\n");
}

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bit_count = 0;

	(void)info;
	(void)context;
	c <<= 1;
	if (signo == SIGUSR2)
		c |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", c);
		c = 0;
		bit_count = 0;
	}
}
