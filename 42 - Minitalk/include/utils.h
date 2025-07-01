/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:21:40 by hurasmi           #+#    #+#             */
/*   Updated: 2025/07/01 12:41:28 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <signal.h>
# include "../libs/ft_printf/includes/ft_printf.h"
# include "../libs/libft/libft.h"
# include "server.h"
#include <sys/types.h>
# include "client.h"

void	print_info(const char *msg);
void	print_error(const char *msg);
void	print_success(const char *msg);

#endif