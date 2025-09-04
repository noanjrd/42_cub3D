/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:05:58 by njard             #+#    #+#             */
/*   Updated: 2025/09/04 14:18:11 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	mouse_hook(int button, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	data = (t_data *)param;
	if (button == 5)
		data->player->planex += 0.1;
	if (button == 3)
		data->player->planey += 0.1;
	if (button == 1)
		data->player->planey -= 0.1;
	if (button == 4)
		data->player->planex -= 0.1;
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	double	degree;

	(void)y;
	degree = 0.03;
	if (x <= WINDOW_WIDTH / 3)
	{
		change_direction(data, -degree);
	}
	if (x >= (WINDOW_WIDTH / 3) * 2)
	{
		change_direction(data, degree);
	}
	return (0);
}

void	change_direction(t_data *data, double degree)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->player->dirx;
	oldplanex = data->player->planex;
	data->player->dirx = data->player->dirx * cos(degree) - data->player->diry
		* sin(degree);
	data->player->diry = olddirx * sin(degree) + data->player->diry
		* cos(degree);
	data->player->planex = data->player->planex * cos(degree)
		- data->player->planey * sin(degree);
	data->player->planey = oldplanex * sin(degree) + data->player->planey
		* cos(degree);
}
