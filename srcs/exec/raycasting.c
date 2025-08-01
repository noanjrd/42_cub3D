/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:17:36 by njard             #+#    #+#             */
/*   Updated: 2025/08/01 16:27:18 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

// static void	put_image(t_fractal **fractal)
// {
// 	mlx_put_image_to_window((*fractal)->mlx, (*fractal)->win,
// 		(*fractal)->img, 0, 0);
// 	return ;
// }

void raycasting(t_data *data, t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			if (y < WINDOW_HEIGHT / 2)
				((int *)mlx->addr)[y * WINDOW_WIDTH + x] = data->ceiling->color;
			else
				((int *)mlx->addr)[y * WINDOW_WIDTH + x] = data->floor->color;
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->img, 0, 0);
		
	mlx_loop(mlx->mlx);
}