/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:26:24 by hurasmi           #+#    #+#             */
/*   Updated: 2025/04/03 09:55:27 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini-fun/minitalk.h"

int main()
{

    pid_t server_pid;

    server_pid = getpid();
    
    if(server_pid)
    {
        ft_printf("SERVER PID: %s", ft_itoa((int)server_pid));
    }
    
    
    
    
    while(1)
    {
        pause();
    }

    return 0;
} 