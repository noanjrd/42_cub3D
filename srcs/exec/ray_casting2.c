/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinguet <mpinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:52:12 by mpinguet          #+#    #+#             */
/*   Updated: 2025/09/14 19:52:12 by mpinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = data->mlx->addr + (y * data->mlx->line_length + x
			* (data->mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_texture_pixel(void *texture_img, int tex_x, int tex_y)
{
	char	*texture_data;
	char	*dst;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	texture_data = mlx_get_data_addr(texture_img, &bits_per_pixel, &line_length,
			&endian);
	dst = texture_data + (tex_y * line_length + tex_x * (bits_per_pixel / 8));
	return (*(int *)dst);
}

void	wall_ver_or_hor(t_data *data)
{
	if (data->player->side == 0)
	{
		if (data->player->ray_dir_x > 0)
			data->wall_texture = data->texture->wall_e;
		else
		{
			data->wall_texture = data->texture->wall_w;
			data->texture->tex_x = 63 - data->texture->tex_x;
		}
	}
	else
	{
		if (data->player->ray_dir_y > 0)
		{
			data->wall_texture = data->texture->wall_s;
			data->texture->tex_x = 63 - data->texture->tex_x;
		}
		else
			data->wall_texture = data->texture->wall_n;
	}
}

void	init_wall_x(double *wall_x, t_data *data)
{
	if (data->player->side == 0)
		*wall_x = data->player->y + data->player->perp_wall_dist
			* data->player->ray_dir_y;
	else
		*wall_x = data->player->x + data->player->perp_wall_dist
			* data->player->ray_dir_x;
	*wall_x -= floor(*wall_x);
	data->texture->tex_x = (int)(*wall_x * 64.0);
}

void	init_draw_start_end(int *draw_start, int *draw_end, int *wall_height,
		double *step)
{
	if (*draw_start < 0)
		*draw_start = 0;
	if (*draw_end >= WINDOW_HEIGHT)
		*draw_end = WINDOW_HEIGHT - 1;
	*wall_height = *draw_end - *draw_start;
	*step = 64.0 / *wall_height;
}
