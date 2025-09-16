/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinguet <mpinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:34:20 by mpinguet          #+#    #+#             */
/*   Updated: 2025/09/16 16:34:20 by mpinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	vertical_line(t_data *data, double *side_dist_x, int step_x, int *side)
{
	*side_dist_x += data->player->delta_x;
	data->player->map_x += step_x;
	*side = 0;
}

void	horizontal_line(t_data *data, double *side_dist_y, int step_y,
		int *side)
{
	*side_dist_y += data->player->delta_y;
	data->player->map_y += step_y;
	*side = 1;
}

void	calcul_perp_wall(t_data *data, int side, int step_x, int step_y)
{
	if (side == 0)
		data->player->perp_wall_dist = (data->player->map_x - data->player->x
				+ (1 - step_x) / 2) / data->player->ray_dir_x;
	else
		data->player->perp_wall_dist = (data->player->map_y - data->player->y
				+ (1 - step_y) / 2) / data->player->ray_dir_y;
}

double	cast_ray(t_data *data, double ray_dir_x, double ray_dir_y)
{
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;

	calcul_cast_ray(data);
	calcul_distance_x(data, &side_dist_x, &step_x);
	calcul_distance_y(data, &side_dist_y, &step_y);
	while (data->player->hit == 0)
	{
		if (side_dist_x < side_dist_y)
			vertical_line(data, &side_dist_x, step_x, &side);
		else
			horizontal_line(data, &side_dist_y, step_y, &side);
		if (ray_touch_wall(data) == 1)
			break ;
		if (data->map->map[data->player->map_y][data->player->map_x] == '1')
			data->player->hit = 1;
	}
	data->player->side = side;
	calcul_perp_wall(data, side, step_x, step_y);
	return (data->player->perp_wall_dist);
}
