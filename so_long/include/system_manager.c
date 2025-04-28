#include "./utils.h"

void game_init(t_game *g)
{
    g->mlx = mlx_init();
    g->win = mlx_new_window(g->mlx, g->win_width, g->win_height, g->title);
}