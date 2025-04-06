/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini-server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:26:29 by hurasmi           #+#    #+#             */
/*   Updated: 2025/04/07 00:26:59 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig)
{
	static char		byte = 0;
	static int		bit_count = 0;

	if (sig == SIGUSR1)
	{
		byte = byte << 1;
	}
	else if (sig == SIGUSR2)
	{
		byte = (byte << 1) | 1;
	}
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", byte);
		if (byte == '\0')
		{
			ft_printf("\n");
		}
		byte = 0;
		bit_count = 0;
	}
	usleep(100);
}
