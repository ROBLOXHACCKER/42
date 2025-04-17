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

    int     move_left;
    int     move_right;
    int     move_up;
    int     move_down;
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

int key_hook_press(int keycode, t_game *game)
{
    if (keycode == 53)
        exit(0);
    else if (keycode == 123)
        game->move_left = 1;
    else if (keycode == 124)
        game->move_right = 1;
    else if (keycode == 125)
        game->move_down = 1;
    else if (keycode == 126)
        game->move_up = 1;
    return (0);
}

int key_hook_release(int keycode, t_game *game)
{
    if (keycode == 123)
        game->move_left = 0;
    else if (keycode == 124)
        game->move_right = 0;
    else if (keycode == 125)
        game->move_down = 0;
    else if (keycode == 126)
        game->move_up = 0;
    return (0);
}

int game_loop(t_game *game)
{
    int moved = 0;
    int speed = 3;
 
    if (game->move_left)
    {
        game->pos_x -= speed;
        moved = 1;
    }
    if (game->move_right)
    {
        game->pos_x += speed;
        moved = 1;
    }
    if (game->move_up)
    {
        game->pos_y -= speed;
        moved = 1;
    }
    if (game->move_down)
    {
        game->pos_y += speed;
        moved = 1;
    }

    if (moved)
    {
        mlx_clear_window(game->mlx, game->win);
        render(game);
    }
    return (0);
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
    game.move_left = 0;
    game.move_right = 0;
    game.move_up = 0;
    game.move_down = 0;

    render(&game);

    mlx_hook(game.win, 2, 1L << 0, key_hook_press, &game);
    mlx_hook(game.win, 3, 1L << 1, key_hook_release, &game);
    mlx_loop_hook(game.mlx, game_loop, &game);

    mlx_loop(game.mlx);
    return (0);
}