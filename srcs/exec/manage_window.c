#include "../../include/cub3D.h"

void free_map(t_map *map)
{
    int i;

    i = 0;
    while(map->map[i])
    {
        free(map->map[i]);
        i++;
    }
    free(map->map);
}

int calcul_display(t_data *data)
{
    char *pixel_addr;
    int x;
    int y;

    y = 0;
    while(y < WINDOW_HEIGHT)
    {
        x = 0;
        while(x < WINDOW_WIDTH)
        {
            pixel_addr = data->mlx->addr + (y * data->mlx->line_length + x * 4);
            *(unsigned int *)pixel_addr = 0xFFFF0000;
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->img, 0, 0);
}

void destroy_window(t_data *data)
{
    mlx_destroy_image(data->mlx->mlx, data->mlx->img);
    mlx_destroy_window(data->mlx->mlx, data->mlx->win);
    mlx_destroy_display(data->mlx->mlx);
    free_map(data->map);
    free(data->map);
    free(data->mlx);
    free(data->ceiling);
    free(data->floor);
    free(data->SO_texture);
    free(data->F_color);
    free(data->C_color);
    free(data->NO_texture);
    free(data->WE_texture);
    free(data->EA_texture);
    free(data);
    free(data->player);
    exit(0);
}
int close_window(t_data *data)
{
    destroy_window(data);
}

int manage_window(int keycode, t_data *data)
{
    if (keycode == 65307)
        destroy_window(data);
}