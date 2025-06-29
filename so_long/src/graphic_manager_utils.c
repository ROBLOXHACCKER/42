/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_manager_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:00:00 by hurasmi           #+#    #+#             */
/*   Updated: 2024/06/07 10:00:00 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/utils.h"

void	count_collectibles(t_game *g, int *total)
{
	int		x;
	int		y;

	*total = 0;
	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'C')
				(*total)++;
			x++;
		}
		y++;
	}
}

void	render_collectible(t_game *g, t_block *b, int x, int y)
{
	t_blockinfo	info;

	info.g = g;
	info.b = b;
	info.x = x;
	info.y = y;
	render_block("./include/textures/collect.xpm", &info);
}

void	render_exit(t_game *g, t_block *b, int x, int y)
{
	t_blockinfo	info;

	info.g = g;
	info.b = b;
	info.x = x;
	info.y = y;
	render_block("./include/textures/exit.xpm", &info);
}

void	render_collectibles_and_exit(t_renderinfo *info)
{
	int		x;
	int		y;

	y = 0;
	while (info->g->map[y])
	{
		x = 0;
		while (info->g->map[y][x])
		{
			if (info->g->map[y][x] == 'C')
				render_collectible(info->g, info->b, x, y);
			if (info->collected == info->total && info->g->map[y][x] == 'E')
				render_exit(info->g, info->b, x, y);
			x++;
		}
		y++;
	}
}

void	put_player_img(t_game *g, t_player *p, t_block *b)
{
	mlx_put_image_to_window(
		g->mlx, g->win, p->img,
		p->x * b->width, p->y * b->height);
}
