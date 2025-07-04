/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <hurasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:10:32 by hurasmi           #+#    #+#             */
/*   Updated: 2025/07/01 16:06:49 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

void	game_init(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->win_width, g->win_height, g->title);
}
