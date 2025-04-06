/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:26:20 by hurasmi           #+#    #+#             */
/*   Updated: 2025/04/06 22:39:53 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini-fun/minitalk.h"

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
    
    char_to_binary('\0', server_pid);
    return 0;
}
