/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:10:00 by hurasmi           #+#    #+#             */
/*   Updated: 2025/07/01 16:09:21 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "utils.h"

void	ft_print_arg(char type, va_list args)
{
	if (type == 's')
		ft_putstr(va_arg(args, char *));
	else if (type == 'd')
		ft_putnbr(va_arg(args, int));
	else
		write(1, &type, 1);
}
