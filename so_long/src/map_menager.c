/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_menager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:00:00 by hurasmi           #+#    #+#             */
/*   Updated: 2024/06/07 10:00:00 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

char	**read_map(const char *filename)
{
	FILE		*file;
	char		**map;
	char		buffer[1024];
	int			i;

	file = fopen(filename, "r");
	if (!file)
	{
		perror("Errore apertura file");
		return (NULL);
	}
	map = malloc(sizeof(char *) * 1024);
	i = 0;
	while (fgets(buffer, sizeof(buffer), file))
	{
		map[i] = ft_strdup(buffer);
		map[i][ft_strcspn(map[i], "\n")] = 0;
		i++;
	}
	map[i] = NULL;
	fclose(file);
	return (map);
}

static void	render_ground_or_wall(char c, t_blockinfo *info)
{
	if (c == '1')
		render_block("./include/textures/wall.xpm", info);
	else if (c == '0' || c == 'C' || c == 'E' || c == 'P')
		render_block("./include/textures/ground.xpm", info);
}

void	create_map(t_game *g, t_block *b, char **map)
{
	int			y;
	int			x;
	t_blockinfo	info;

	y = 0;
	info.g = g;
	info.b = b;
	while (map[y])
	{
		x = 0;
		info.y = y;
		while (map[y][x])
		{
			info.x = x;
			render_ground_or_wall(map[y][x], &info);
			x++;
		}
		y++;
	}
}

void	render_block(char *path, t_blockinfo *info)
{
	info->b->img = mlx_xpm_file_to_image(
			info->g->mlx, path, &info->b->width, &info->b->height);
	if (!info->b->img)
	{
		ft_printf("Errore caricamento immagine: %s\n", path);
		return ;
	}
	mlx_put_image_to_window(
		info->g->mlx, info->g->win,
		info->b->img, info->x * info->b->width, info->y * info->b->height);
}
