#include "./minilibx_opengl_20191021/mlx.h"
#include "./utils.h"

int key_hook_press(int keycode, t_player *p)
{
    if (keycode == 53)
        exit(0);
    else if (keycode == 123)
        p->move.move_left = 1;
    else if (keycode == 124)
        p->move.move_right = 1;
    else if (keycode == 125)
        p->move.move_down = 1;
    else if (keycode == 126)
        p->move.move_up = 1;
    return (0);
}

int key_hook_release(int keycode, t_player *p)
{
    if (keycode == 123)
        p->move.move_left = 0;
    else if (keycode == 124)
        p->move.move_right = 0;
    else if (keycode == 125)
        p->move.move_down = 0;
    else if (keycode == 126)
        p->move.move_up = 0;
    return (0);
}

int game_loop(void *param)
{
    t_context *ctx = (t_context *)param;
    t_game *g = ctx->g;
    t_player *p = ctx->p;
    int moved = 0;

    if (p->move.move_left)
    {
        p->move.pos_x -= p->move.speed;
        moved = 1;
    }
    if (p->move.move_right)
    {
        p->move.pos_x += p->move.speed;
        moved = 1;
    }
    if (p->move.move_up)
    {
        p->move.pos_y -= p->move.speed;
        moved = 1;
    }
    if (p->move.move_down)
    {
        p->move.pos_y += p->move.speed;
        moved = 1;
    }

    if (moved)
    {
        mlx_clear_window(g->mlx, g->win);
        render(g, p);
    }
    return (0);
}

void key_menager(t_player *p, t_game *g, t_context *c)
{
    mlx_hook(g->win, 2, 1L << 0, key_hook_press, p);
    mlx_hook(g->win, 3, 1L << 1, key_hook_release, p);
    c->g = g;
    c->p = p;
    mlx_loop_hook(g->mlx, game_loop, c);
}