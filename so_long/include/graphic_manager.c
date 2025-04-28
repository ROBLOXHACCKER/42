#include "./utils.h"

void render(t_game *g, t_player *p, t_block *b)
{
    static int total_collectibles = -1;
    static int collected = 0;
    int x, y;

    if (total_collectibles == -1)
    {
        total_collectibles = 0;
        for (y = 0; g->map[y]; y++)
            for (x = 0; g->map[y][x]; x++)
                if (g->map[y][x] == 'C')
                    total_collectibles++;
    }

    // Se il player è sopra un collezionabile
    if (g->map[p->y][p->x] == 'C')
    {
        g->map[p->y][p->x] = '0';
        collected++;
    }

    mlx_clear_window(g->mlx, g->win);
    create_map(g, b, g->map);

    // Dopo create_map, disegna solo elementi dinamici
    for (y = 0; g->map[y]; y++)
    {
        for (x = 0; g->map[y][x]; x++)
        {
            if (g->map[y][x] == 'C') // disegna reward sopra ground
                render_block("./include/textures/collect.xpm", g, b, x, y);
            if (collected == total_collectibles && g->map[y][x] == 'E') // disegna uscita solo dopo
                render_block("./include/textures/exit.xpm", g, b, x, y);
        }
    }

    // Disegna player sopra tutto
    mlx_put_image_to_window(g->mlx, g->win, p->img, p->x * b->width, p->y * b->height);

    // Se player è sull'uscita dopo aver preso tutto, termina
    if (collected == total_collectibles && g->map[p->y][p->x] == 'E')
    {
        printf("Hai vinto!\n");
        exit(0);
    }
}