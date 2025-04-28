#ifndef UTILS_H
# define UTILS_H

#include "./minilibx_opengl_20191021/mlx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Strutture dati
typedef struct s_block
{
    void *img;
    int width;
    int height;
} t_block;

typedef struct s_player {
    void *img;
    int x;
    int y;
} t_player;

typedef struct s_game
{
    void *mlx;
    void *win;
    int win_width;
    int win_height;
    char *title;
    char **map;
    t_player player;
    t_block block;
} t_game;

// Funzioni
void game_init(t_game *g);
void render(t_game *g, t_player *p, t_block *b);
void key_manager(t_game *g, void *unused);
void render_block(char *path, t_game *g, t_block *b, int x, int y);
void create_map(t_game *g, t_block *b, char **map);
char **read_map(const char *filename);

#endif