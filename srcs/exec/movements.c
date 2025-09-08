/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:05:58 by njard             #+#    #+#             */
/*   Updated: 2025/09/08 17:02:18 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	move_player_forward(t_data *data)
{
	if (check_wall(data->map->map, (int)(data->player->posy
			+ data->player->diry * 0.01), (int)(data->player->posx
		+ data->player->dirx * 0.01)) == 0)
	{
		data->player->posx += data->player->dirx * 0.01;
		data->player->posy += data->player->diry * 0.01;
	}
}

void	move_player_backward(t_data *data)
{
	if (check_wall(data->map->map, (int)(data->player->posy
			- data->player->diry * 0.01), (int)(data->player->posx
		- data->player->dirx * 0.01)) == 0)
	{
		data->player->posx -= data->player->dirx * 0.01;
		data->player->posy -= data->player->diry * 0.01;
	}
}

void	move_player_left(t_data *data)
{
	if (check_wall(data->map->map, (int)(data->player->posy
			- data->player->planey * 0.01), (int)(data->player->posx
		- data->player->planex * 0.01)) == 0)
	{
		data->player->posx -= data->player->planex * 0.01;
		data->player->posy -= data->player->planey * 0.01;
	}
}

void	move_player_right(t_data *data)
{
	if (check_wall(data->map->map, (int)(data->player->posy
			+ data->player->planey * 0.01), (int)(data->player->posx
		+ data->player->planex * 0.01)) == 0)
	{
		data->player->posx += data->player->planex * 0.01;
		data->player->posy += data->player->planey * 0.01;
	}
}

void	rotate_player(t_data *data, double degree)
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
