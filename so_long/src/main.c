#include "../include/utils.h"

int main(void)
{
    t_game game;
    t_block block = {0};
    char **map;
    int img_w, img_h;

    block.width = 32;
    block.height = 32;

    game.block = block;
    game.title = "so_long";
    game.win_width = 600;
    game.win_height = 400;

    game_init(&game);

    game.player.img = mlx_xpm_file_to_image(game.mlx, "./include/textures/player.xpm", &img_w, &img_h);
    game.player.x = 1;
    game.player.y = 1;

    map = read_map("./map/map.ber");
    if (!map)
    {
        printf("Errore: impossibile leggere la mappa\n");
        return 1;
    }
    game.map = map;

    create_map(&game, &block, map);
    render(&game, &game.player, &game.block);

    key_manager(&game, NULL);

    mlx_loop(game.mlx);
    return 0;
}