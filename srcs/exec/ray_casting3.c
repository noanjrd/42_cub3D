/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinguet <mpinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:33:28 by mpinguet          #+#    #+#             */
/*   Updated: 2025/09/16 16:33:28 by mpinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	init_delta(t_data *data)
{
	if (data->player->ray_dir_x == 0)
		data->player->delta_x = 1e30;
	else
	{
		if (data->player->ray_dir_x < 0)
			data->player->delta_x = -(1 / data->player->ray_dir_x);
		else
			data->player->delta_x = 1 / data->player->ray_dir_x;
	}
	if (data->player->ray_dir_y == 0)
		data->player->delta_y = 1e30;
	else
	{
		if (data->player->ray_dir_y < 0)
			data->player->delta_y = -(1 / data->player->ray_dir_y);
		else
			data->player->delta_y = 1 / data->player->ray_dir_y;
	}
}

void	calcul_distance_x(t_data *data, double *side_dist_x, int *step_x)
{
	if (data->player->ray_dir_x < 0)
	{
		*step_x = -1;
		*side_dist_x = (data->player->x - data->player->map_x)
			* data->player->delta_x;
	}
	else
	{
		*step_x = 1;
		*side_dist_x = (data->player->map_x + 1.0 - data->player->x)
			* data->player->delta_x;
	}
}

void	calcul_distance_y(t_data *data, double *side_dist_y, int *step_y)
{
	if (data->player->ray_dir_y < 0)
	{
		*step_y = -1;
		*side_dist_y = (data->player->y - data->player->map_y)
			* data->player->delta_y;
	}
	else
	{
		*step_y = 1;
		*side_dist_y = (data->player->map_y + 1.0 - data->player->y)
			* data->player->delta_y;
	}
}
