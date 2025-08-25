/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:35:40 by njard             #+#    #+#             */
/*   Updated: 2025/08/25 15:15:20 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void init_mlx(t_data *data)
{
	data->mlx->mlx = mlx_init();
	if (!data->mlx->mlx)
	{
		return ;
	}
	data->mlx->win = mlx_new_window(data->mlx->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	data->mlx->img = mlx_new_image(data->mlx->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img,
			&data->mlx->bits_per_pixel, &data->mlx->line_length, &data->mlx->endian);
	raycasting(data, data->mlx, data->game, data->player);

}
