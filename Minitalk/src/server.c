/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:26:24 by hurasmi           #+#    #+#             */
/*   Updated: 2025/04/06 00:06:15 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini-fun/minitalk.h"

void handle_signal(int sig)
{
    static char byte = 0;
    static int bit_count = 0;

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
        ft_printf("%c\n", byte);
        byte = 0;
        bit_count = 0;
    }
    usleep(100); 
}

int main()
{
    pid_t server_pid;
    
    server_pid = getpid();
    
    if(server_pid)
    {
        ft_printf("SERVER PID: %s\n", ft_itoa((int)server_pid));
    }

    struct sigaction sa;

    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    
    
   
    
    while(1)
    {
        pause();
    }

    return 0;
} 