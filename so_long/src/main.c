/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:00:00 by hurasmi           #+#    #+#             */
/*   Updated: 2024/06/07 10:00:00 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/utils.h"

void	init_block(t_block *block)
{
	block->width = 32;
	block->height = 32;
}

void	init_game(t_game *game, t_block *block)
{
	game->block = *block;
	game->title = "so_long";
	game->win_width = 1600;
	game->win_height = 1400;
	game_init(game);
}

void	init_player(t_game *game)
{
	int	img_w;
	int	img_h;

	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"./include/textures/player.xpm", &img_w, &img_h);
	game->player.x = 1;
	game->player.y = 1;
}

int	main(void)
{
	t_game	game;
	t_block	block;
	char	**map;

	init_block(&block);
	init_game(&game, &block);
	init_player(&game);
	map = read_map("./map/map.ber");
	if (!map)
	{
		printf("Errore: impossibile leggere la mappa\n");
		return (1);
	}
	game.map = map;
	create_map(&game, &block, map);
	render(&game, &game.player, &game.block);
	key_manager(&game, NULL);
	mlx_loop(game.mlx);
	return (0);
}
