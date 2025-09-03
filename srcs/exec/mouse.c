/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:05:58 by njard             #+#    #+#             */
/*   Updated: 2025/09/03 20:58:23 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"


//cette focntion est un bonus
int	mouse_hook(int button, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	data = (t_data *)param;
	if (button == 5)
		data->player->planeX += 0.1;

	if (button == 3)
		data->player->planeY += 0.1;

	if (button == 1)
		data->player->planeY -= 0.1;
	
	if (button == 4)
		data->player->planeX -= 0.1;
	return (0);
}

int	mouse_move( int x, int y, t_data *data)
{
	double degree;

	degree = 0.03;
	if (x <= WINDOW_WIDTH / 3)
	{
		change_direction(data, -degree);
	}
	if (x >= (WINDOW_WIDTH / 3) * 2 )
	{
		change_direction(data, degree);
	}
	return (0);
}

void change_direction(t_data *data, double degree )
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = data->player->dirX;
	oldPlaneX = data->player->planeX;
	data->player->dirX = data->player->dirX
		* cos(degree) - data->player->dirY * sin(degree);
	data->player->dirY = oldDirX * sin(degree)
		+ data->player->dirY * cos(degree);
	data->player->planeX = data->player->planeX
		* cos(degree) - data->player->planeY * sin(degree);
	data->player->planeY = oldPlaneX * sin(degree)
		+ data->player->planeY * cos(degree);
}
