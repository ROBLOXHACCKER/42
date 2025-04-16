#include "../include/utils.h"
#include <stdlib.h> // per exit

typedef struct s_game
{
    void    *mlx;
    void    *win;
    void    *image;
    int     *data;
    int     img_width;
    int     img_height;
    int     win_width;
    int     win_height;
    int     bpp;
    int     size_line;
    int     endian;
    int     pos_x;
    int     pos_y;
    int     color;
    char    *win_title;
}   t_game;


void draw_square(t_game *game)
{
    int i = 0;
    while(i < (game->img_height * game->img_width))
        game->data[i++] = game->color;
}

void render(t_game *game)
{
    game->image = mlx_new_image(game->mlx, game->img_width, game->img_height);
    game->data = (int *)mlx_get_data_addr(game->image, &game->bpp, &game->size_line, &game->endian);
    draw_square(game);
    mlx_put_image_to_window(game->mlx, game->win, game->image, game->pos_x, game->pos_y);
    mlx_destroy_image(game->mlx, game->image);
}

int key_hook(int keycode, t_game *game)
{
    if (keycode == 53)
        exit(0);
    else if (keycode == 123)
        game->pos_x -= 10;
    else if (keycode == 124) 
        game->pos_x += 10;
    else if (keycode == 125) 
        game->pos_y += 10;
    else if (keycode == 126) 
        game->pos_y -= 10;

    mlx_clear_window(game->mlx, game->win);
    render(game);
    return 0;
}

int main(void)
{
    t_game game;
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, 600, 400, "so_long");
    game.img_width = 10;
    game.img_height = 10;
    game.color = 0x00FF00;
    game.pos_x = 10;
    game.pos_y = 10;

    render(&game);
    mlx_key_hook(game.win, key_hook, &game);
    mlx_loop(game.mlx);

    return (0);
}