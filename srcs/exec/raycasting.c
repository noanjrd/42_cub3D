/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:17:36 by njard             #+#    #+#             */
/*   Updated: 2025/08/25 16:08:02 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

// static void	put_image(t_fractal **fractal)
// {
// 	mlx_put_image_to_window((*fractal)->mlx, (*fractal)->win,
// 		(*fractal)->img, 0, 0);
// 	return ;
// }

void draw_floor_ceiling(t_data *data, t_mlx *mlx)
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
}

void raycasting(t_data *data, t_mlx *mlx, t_game *game, t_player *player)
{
	draw_floor_ceiling(data, mlx);

	int x;

	while(!done())
	{
		int w = 0;
		for(int x = 0; x < w; x++)
		{
			double cameraX = 2 * x / (double)w - 1;
			double rayDirX = player->dirX + player->planeX * cameraX;
			double rayDirY = player->dirY + player->planeY * cameraX;
		}
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img, 0, 0);
	}
	mlx_loop(mlx->mlx);
}