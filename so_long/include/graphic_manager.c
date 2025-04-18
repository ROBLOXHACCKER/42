#include "./minilibx_opengl_20191021/mlx.h"
#include "./utils.h"

void create_player(t_player *p, t_game *g)
{
    p->img = mlx_new_image(g->mlx, p->size_x, p->size_y);
    p->data = (int*)mlx_get_data_addr(p->img, &p->bpp, &p->size_line, &p->endian);
}

void draw_square(t_player *p)
{
    int i = 0;
    while(i < p->size_x * p->size_y)
        p->data[i++] = p->color;
}

void render(t_game *g, t_player *p)
{
    create_player(p, g);
    draw_square(p);
    mlx_put_image_to_window(g->mlx, g->win, p->img, p->move.pos_x, p->move.pos_y);
    mlx_destroy_image(g->mlx, p->img);
}

