/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_menager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:00:00 by hurasmi           #+#    #+#             */
/*   Updated: 2024/06/07 10:00:00 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./utils.h"

static void	move_player(int keycode, t_game *g, t_player *p, int *move_count)
{
	if (keycode == 123 && g->map[p->y][p->x - 1] != '1')
	{
		p->x--;
		(*move_count)++;
		ft_printf("%d\n", *move_count);
	}
	else if (keycode == 124 && g->map[p->y][p->x + 1] != '1')
	{
		p->x++;
		(*move_count)++;
		ft_printf("%d\n", *move_count);
	}
	else if (keycode == 125 && g->map[p->y + 1][p->x] != '1')
	{
		p->y++;
		(*move_count)++;
		ft_printf("%d\n", *move_count);
	}
	else if (keycode == 126 && g->map[p->y - 1][p->x] != '1')
	{
		p->y--;
		(*move_count)++;
		ft_printf("%d\n", *move_count);
	}
}

int	key_hook(int keycode, t_game *g)
{
	static int	move_count;
	t_player	*p;

	p = &(g->player);
	if (keycode == 53)
		exit(0);
	move_player(keycode, g, p, &move_count);
	render(g, p, &(g->block));
	return (0);
}

void	key_manager(t_game *g, void *unused)
{
	(void)unused;
	mlx_hook(g->win, 2, 1L << 0, key_hook, g);
}
