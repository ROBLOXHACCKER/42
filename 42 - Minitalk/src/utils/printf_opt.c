/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:14:20 by hurasmi           #+#    #+#             */
/*   Updated: 2025/07/01 11:37:40 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

void	print_info(const char *msg)
{
	ft_printf("\033[36m[INFO]\033[0m %s\n", msg);
}

void	print_error(const char *msg)
{
	ft_printf("\033[31m[ERRORE]\033[0m %s\n", msg);
}

void	print_success(const char *msg)
{
	ft_printf("\033[32m[OK]\033[0m %s\n", msg);
}
