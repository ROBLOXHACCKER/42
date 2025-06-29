/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:00:00 by hurasmi           #+#    #+#             */
/*   Updated: 2024/06/07 10:00:00 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/utils.h"

void	render_end(t_renderendinfo *e)
{
	t_renderinfo	info;

	info.g = e->g;
	info.p = e->p;
	info.b = e->b;
	info.collected = e->collected;
	info.total = e->total_collectibles;
	render_collectibles_and_exit(&info);
	put_player_img(e->g, e->p, e->b);
	if (e->collected == e->total_collectibles \
		&& e->g->map[e->p->y][e->p->x] == 'E')
	{
		ft_printf("Hai vinto!\n");
		exit(0);
	}
}

void	render(t_game *g, t_player *p, t_block *b)
{
	static int		total_collectibles = -1;
	static int		collected = 0;
	t_renderendinfo	info;

	if (total_collectibles == -1)
		count_collectibles(g, &total_collectibles);
	if (g->map[p->y][p->x] == 'C')
	{
		g->map[p->y][p->x] = '0';
		collected++;
	}
	mlx_clear_window(g->mlx, g->win);
	create_map(g, b, g->map);
	info.g = g;
	info.p = p;
	info.b = b;
	info.collected = collected;
	info.total_collectibles = total_collectibles;
	render_end(&info);
}
