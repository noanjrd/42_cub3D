/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_columns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinguet <mpinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:51:51 by mpinguet          #+#    #+#             */
/*   Updated: 2025/09/14 19:51:51 by mpinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	transfo_color(char *color, int *r, int *g, int *b)
{
    char		**tab;

    tab = ft_split(color, ',');
    *r = ft_atoi(tab[0]);
    *g = ft_atoi(tab[1]);
    *b = ft_atoi(tab[2]);
    free_split(tab);
}

void	color_ceil_floor(t_data *data, int n)
{
    int		hex_color;
    int		r;
    int		g;
    int		b;

    if (n == 1)
    {
        transfo_color(data->c_color, &r, &g, &b);
        data->texture->col_ceil = ((r << 16) | (g << 8) | b);
    }
    if (n == 0)
    {
        transfo_color(data->f_color, &r, &g, &b);
        data->texture->col_floor = ((r << 16) | (g << 8) | b);
    }
}

void	draw_column(t_data *data, int x, int draw_start, int draw_end)
{
    int		y;
    int		wall_height;
    double	step;
    double	wall_x;
   
    init_draw_start_end(&draw_start, &draw_end, &wall_height, &step);
    init_wall_x(&wall_x, data);
    wall_ver_or_hor(data);
    data->texture->tex_pos = (draw_start - WINDOW_HEIGHT / 2 + wall_height / 2) * step;
    y = 0;
    while (y < draw_start)
        my_mlx_pixel_put(data, x, y++, data->texture->col_ceil);
    y = draw_start;
    while (y <= draw_end)
    {
        data->texture->tex_y = (int)data->texture->tex_pos & 63;
        data->texture->tex_pos += step;
        data->texture->color = get_texture_pixel(data,
            data->wall_texture, data->texture->tex_x,
            data->texture->tex_y);
        my_mlx_pixel_put(data, x, y++, data->texture->color);
    }
    y = draw_end + 1;
    while (y < WINDOW_HEIGHT)
        my_mlx_pixel_put(data, x, y++, data->texture->col_floor);
}

void	clear_image(t_data *data)
{
    int		x;
    int		y;

    x = 0;    
    while (x < WINDOW_WIDTH)
    {
        y = 0;
        while (y < WINDOW_HEIGHT)
        {
            my_mlx_pixel_put(data, x, y, 0x000000);
            y++;
        }
        x++;
    }
}
