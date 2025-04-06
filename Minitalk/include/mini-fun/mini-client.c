/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini-client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:26:27 by hurasmi           #+#    #+#             */
/*   Updated: 2025/04/07 00:23:06 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_binary(char c, int pid_server)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			kill(pid_server, SIGUSR2);
		}
		else
		{
			kill(pid_server, SIGUSR1);
		}
		i--;
		usleep(100);
	}
}
