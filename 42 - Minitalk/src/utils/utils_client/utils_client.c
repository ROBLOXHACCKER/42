/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 08:49:10 by hurasmi           #+#    #+#             */
/*   Updated: 2025/07/01 13:51:42 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/utils.h"

int	check_input(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (1);
	if (argv[2][0] == '\0')
		return (1);
	if (kill(pid, 0) == -1)
		return (1);
	return (0);
}

void	send_message(pid_t server_pid, const char *msg)
{
	while (*msg)
	{
		send_char(server_pid, *msg);
		msg++;
	}
	send_char(server_pid, '\0');
}

void	send_char(pid_t server_pid, char c)
{
	int	count_bit;
	int	bit;

	count_bit = 8;
	while (count_bit--)
	{
		bit = (c >> count_bit) & 1;
		if (bit)
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				print_error("Errore nell'invio del segnale");
				exit(1);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				print_error("Errore nell'invio del segnale");
				exit(1);
			}
		}
		usleep(300);
	}
}
