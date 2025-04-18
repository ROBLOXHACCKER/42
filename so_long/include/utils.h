#include "./minilibx_opengl_20191021/mlx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_movement
{
    int pos_x;
    int pos_y;
    int move_left;
    int move_right;
    int move_down;
    int move_up;
    int speed;
}t_movement;

typedef struct s_player
{
    void* img;
    int*  data;
    int   color;
    int   size_x;
    int   size_y;
    int   bpp;
    int   size_line;
    int   endian;
    t_movement move;
}t_player;

typedef struct s_game
{
    void  *mlx;
    void  *win;
    int   win_width;
    int   win_height;
    char* title;

}t_game;

typedef struct s_context {
    t_game *g;
    t_player *p;
} t_context;

//system manager
void game_init(t_game *g);

//graphic manager
void draw_square(t_player *p);
void create_player(t_player *p, t_game *g);
void render(t_game *g, t_player *p);

// key manager
int key_hook_press(int keycode, t_player *p);
int key_hook_release(int keycode, t_player *p);
int game_loop(void *param);
void key_menager(t_player *p, t_game *g, t_context *c);

