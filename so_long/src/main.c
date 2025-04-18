#include "../include/utils.h"


int main(void)
{
    t_game game;
    t_player player;
    t_context ctx;
    
    game.title = "so_long";
    game.win_height = 400;
    game.win_width = 600;

    player.color = 0x00FF00;
    player.move.pos_x = 10;
    player.move.pos_y = 10;
    player.size_x = 40;
    player.size_y = 40;
    player.move.speed = 3;
    player.move.move_down = 0;
    player.move.move_left = 0;
    player.move.move_up = 0;
    player.move.move_right = 0;

    game_init(&game);

    render(&game, &player);

    key_menager(&player, &game, &ctx);

    mlx_loop(game.mlx);
    return (0);
}