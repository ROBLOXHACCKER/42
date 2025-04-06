/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:26:33 by hurasmi           #+#    #+#             */
/*   Updated: 2025/04/06 22:49:08 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "../ft_printf/includes/ft_printf.h"
# include "../ft_printf/includes/libft.h"
# include <unistd.h>    
# include <sys/types.h>  
# include <signal.h>

void	handle_signal(int sig);
void	char_to_binary(char c, int pid_server);

#endif