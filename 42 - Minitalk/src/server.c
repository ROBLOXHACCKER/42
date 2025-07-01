/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:00:34 by hurasmi           #+#    #+#             */
/*   Updated: 2025/07/01 11:43:01 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../include/server.h"
#include "../include/utils.h"

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid_server;

	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid_server = getpid();
	print_server_banner(pid_server);
	while (1)
	{
		pause();
	}
	return (0);
}
