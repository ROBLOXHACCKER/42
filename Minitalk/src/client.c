/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:26:20 by hurasmi           #+#    #+#             */
/*   Updated: 2025/04/05 22:20:25 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini-fun/minitalk.h"

void char_to_binary(char c, int pid_server)
{
    int i = 7;
    printf("\nLETTERA %c\n", c);
    while(i >= 0)
    {
        if((c >> i) & 1)
        {
            kill(pid_server, SIGUSR2);
        }
        else
        {
            kill(pid_server, SIGUSR1);
        }
        i--;
    }
}

int main(int argc, char *argv[])
{
    if(argc != 3 || ft_atoi(argv[1]) <= 0 || kill(ft_atoi(argv[1]), 0) != 0)
    {
        printf("Errore: parametri input sbagliati");
        return -1;
    }
    int server_pid = ft_atoi(argv[1]);
    char *message_to_server;

    message_to_server = argv[2];
    while(*message_to_server != '\0')
    {
        char_to_binary(*message_to_server, server_pid);
        message_to_server++;
    }   

    return 0;
}
