/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinguet <mpinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:51:31 by mpinguet          #+#    #+#             */
/*   Updated: 2025/09/14 19:51:31 by mpinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void init_texture(t_data *data)
{

    data->texture->wall_n = mlx_xpm_file_to_image(data->mlx->mlx, data->no_texture, &data->texture->width, &data->texture->height);
    data->texture->wall_s = mlx_xpm_file_to_image(data->mlx->mlx, data->so_texture, &data->texture->width, &data->texture->height);
    data->texture->wall_e = mlx_xpm_file_to_image(data->mlx->mlx, data->ea_texture, &data->texture->width, &data->texture->height);
    data->texture->wall_w = mlx_xpm_file_to_image(data->mlx->mlx, data->we_texture, &data->texture->width, &data->texture->height);
    color_ceil_floor(data, 0);
	color_ceil_floor(data, 1);
}
int calcul_display(t_data *data)
{
    int x = 0;
    double wall_dist;
    int draw_start;
    int draw_end;
    
    clear_image(data);
    key_action(data);
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

void arrow_left(t_data *data)
{
    double old_plane_x;
    double angle;
    double cos_a;
    double sin_a;
    double old_dir_x;

    angle = -0.1;
    cos_a = cos(angle);
    sin_a = sin(angle);
    old_dir_x = data->player->dir_x;
    data->player->dir_x = data->player->dir_x * cos_a - data->player->dir_y * sin_a;
    data->player->dir_y = old_dir_x * sin_a + data->player->dir_y * cos_a;
    old_plane_x = data->player->plane_x;
    data->player->plane_x = data->player->plane_x * cos_a - data->player->plane_y * sin_a;
    data->player->plane_y = old_plane_x * sin_a + data->player->plane_y * cos_a;
}
void arrow_right(t_data *data)
{
    double old_plane_x;
    double angle;
    double cos_a;
    double sin_a;
    double old_dir_x;

    angle = 0.1;
    cos_a = cos(angle);
    sin_a = sin(angle);
    old_dir_x = data->player->dir_x;
    data->player->dir_x = data->player->dir_x * cos_a - data->player->dir_y * sin_a;
    data->player->dir_y = old_dir_x * sin_a + data->player->dir_y * cos_a;
    old_plane_x = data->player->plane_x;
    data->player->plane_x = data->player->plane_x * cos_a - data->player->plane_y * sin_a;
    data->player->plane_y = old_plane_x * sin_a + data->player->plane_y * cos_a;

}

int touch_wall(t_data *data)
{
    int y;
    int x;

    if (data->move_up == 1)
    {
        y = floor(data->player->y + (0.2 * data->player->dir_y));
        x = floor(data->player->x + (0.2 * data->player->dir_x));
    }
    else if (data->move_down == 1)
    {
        y = floor(data->player->y - (0.2 * data->player->dir_y));
        x = floor(data->player->x - (0.2 * data->player->dir_x));
    }
    else if (data->move_left == 1)
    {
        y = floor(data->player->y - (0.2 * data->player->plane_y));
        x = floor(data->player->x - (0.2 * data->player->plane_x));
    }
    else if (data->move_right == 1)
    {
        y = floor(data->player->y + (0.2 * data->player->plane_y));
        x = floor(data->player->x + (0.2 * data->player->plane_x));
    }
    if (data->map->map[y][x] == '1')
        return (1);
    return (0);
}