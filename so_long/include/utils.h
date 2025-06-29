/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurasmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:00:00 by hurasmi           #+#    #+#             */
/*   Updated: 2024/06/07 10:00:00 by hurasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "./minilibx_opengl_20191021/mlx.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_block
{
	void		*img;
	int			width;
	int			height;
}	t_block;

typedef struct s_player
{
	void		*img;
	int			x;
	int			y;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	char		*title;
	char		**map;
	t_player	player;
	t_block		block;
}	t_game;

typedef struct s_blockinfo
{
	t_game		*g;
	t_block		*b;
	int			x;
	int			y;
}	t_blockinfo;

typedef struct s_renderendinfo
{
	t_game		*g;
	t_player	*p;
	t_block		*b;
	int			collected;
	int			total_collectibles;
}	t_renderendinfo;

typedef struct s_renderinfo
{
	t_game		*g;
	t_player	*p;
	t_block		*b;
	int			collected;
	int			total;
}	t_renderinfo;

void	game_init(t_game *g);
void	render(t_game *g, t_player *p, t_block *b);
void	key_manager(t_game *g, void *unused);
void	render_block(char *path, t_blockinfo *info);
void	create_map(t_game *g, t_block *b, char **map);
char	**read_map(const char *filename);
void	count_collectibles(t_game *g, int *total);
void	render_collectible(t_game *g, t_block *b, int x, int y);
void	render_exit(t_game *g, t_block *b, int x, int y);
void	render_collectibles_and_exit(t_renderinfo *info);
void	put_player_img(t_game *g, t_player *p, t_block *b);
char	*ft_strdup(const char *s);
size_t	ft_strcspn(const char *s, const char *reject);
int		ft_printf(const char *format, ...);

#endif