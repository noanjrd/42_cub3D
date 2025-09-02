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
    int x = 0;
    double wall_dist;
    int draw_start;
    int draw_end;
    
    // calcul_player(data);
    while (x < WINDOW_WIDTH)
    {
        data->player->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
        data->player->ray_dir_x = data->player->dir_x + data->player->plane_x * data->player->camera_x;
        data->player->ray_dir_y = data->player->dir_y + data->player->plane_y * data->player->camera_x;
        wall_dist = cast_ray(data, data->player->ray_dir_x, data->player->ray_dir_y);
        data->mlx->line_height = (int)(WINDOW_HEIGHT / wall_dist);
        draw_start = -(data->mlx->line_height) / 2 + WINDOW_HEIGHT / 2;
        draw_end = data->mlx->line_height / 2 + WINDOW_HEIGHT / 2;
        draw_column(data, x, draw_start, draw_end);
        x++;
    }
    mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->img, 0, 0);
    return (0);
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

int key_action(int keycode, t_data *data)
{
    printf("x = %f et y = %f", data->player->x, data->player->y);
    if (keycode == 119)
    {
        data->player->y -= 0.2;
        printf("W\n");
    }
    if (keycode == 115)
    {
        data->player->y += 0.2;
        printf("S\n");        
    }
    if (keycode == 97)
    {
        data->player->x -= 0.2;
        printf("A\n");        
    }
    if (keycode == 100)
    {
        data->player->x += 0.2;
        printf("D\n");        
    }
}