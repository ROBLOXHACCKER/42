/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:26:20 by hurasmi           #+#    #+#             */
/*   Updated: 2025/04/03 09:55:36 by hurasmi          ###   ########.fr       */
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

    
    


    

    return 0;
}