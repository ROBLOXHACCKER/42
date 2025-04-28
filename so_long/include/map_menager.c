#include "./utils.h"

char **read_map(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Errore apertura file");
        return NULL;
    }
    char **map = malloc(sizeof(char *) * 1024); // massimo 1024 righe
    char buffer[1024];
    int i = 0;

    while (fgets(buffer, sizeof(buffer), file))
    {
        map[i] = strdup(buffer);
        map[i][strcspn(map[i], "\n")] = 0; // rimuove newline
        i++;
    }
    map[i] = NULL;
    fclose(file);
    return map;
}

void create_map(t_game *g, t_block *b, char **map)
{
    int y = 0;
    while (map[y])
    {
        int x = 0;
        while (map[y][x])
        {
            if (map[y][x] == '1') // muro
                render_block("./include/textures/wall.xpm", g, b, x, y);
            else if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'E' || map[y][x] == 'P')
                render_block("./include/textures/ground.xpm", g, b, x, y);
            x++;
        }
        y++;
    }
}

void render_block(char *path, t_game *g, t_block *b, int x, int y)
{
    b->img = mlx_xpm_file_to_image(g->mlx, path, &b->width, &b->height);
    if (!b->img)
    {
        printf("Errore caricamento immagine: %s\n", path);
        return;
    }
    mlx_put_image_to_window(g->mlx, g->win, b->img, x * b->width, y * b->height);
}