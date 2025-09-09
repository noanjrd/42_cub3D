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

void free_split(char **tab)
{
    int i;

    i = 0;
    while(tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
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
    free(data->player);
    free(data->texture);
    free(data);
    exit(0);
}