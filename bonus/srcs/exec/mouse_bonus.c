/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:05:58 by njard             #+#    #+#             */
/*   Updated: 2025/09/04 14:14:43 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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
