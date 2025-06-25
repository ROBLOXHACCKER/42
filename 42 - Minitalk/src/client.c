/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:28:29 by hurasmi           #+#    #+#             */
/*   Updated: 2025/06/25 09:55:10 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../include/server.h"
#include "../include/utils.h"

int	main(int argc, char **argv)
{
	pid_t	pid_server;
	char	*msg;

	if (check_input(argc, argv))
	{
		print_error("How to use: ./client <PID_server> <messaggio>");
		return (1);
	}
	msg = argv[2];
	pid_server = ft_atoi(argv[1]);
	send_message(pid_server, msg);
	return (0);
}
