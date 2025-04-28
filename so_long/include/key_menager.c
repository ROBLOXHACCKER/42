#include "./utils.h"

int key_hook(int keycode, t_game *g)
{
    static int move_count = 0;
    t_player *p = &(g->player);

    if (keycode == 53) // ESC
        exit(0);
    else if (keycode == 123 && g->map[p->y][p->x - 1] != '1') // sinistra
    {
        p->x--;
        move_count++;
        printf("%d\n", move_count);
    }
    else if (keycode == 124 && g->map[p->y][p->x + 1] != '1') // destra
    {
        p->x++;
        move_count++;
        printf("%d\n", move_count);
    }
    else if (keycode == 125 && g->map[p->y + 1][p->x] != '1') // giù
    {
        p->y++;
        move_count++;
        printf("%d\n", move_count);
    }
    else if (keycode == 126 && g->map[p->y - 1][p->x] != '1') // su
    {
        p->y--;
        move_count++;
        printf("%d\n", move_count);
    }

    render(g, p, &(g->block));
    return 0;
}

void key_manager(t_game *g, void *unused)
{
    (void)unused;
    mlx_hook(g->win, 2, 1L << 0, key_hook, g);
}