/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:35:40 by njard             #+#    #+#             */
/*   Updated: 2025/08/28 15:20:58 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	mouse_hook(int button, int x, int y, void *param)
{
	t_data	*data;

	printf("%d\n", button);

	printf("%d\n", x);
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
	// else if (button == 4)
	// 	fractal->zoom *= 0.9;
	raycasting(data, data->mlx, data->game, data->player);
	return (0);
}

int	mouse_move( int x, int y, void *param)
{
	t_data	*data;


	printf("%d\n", x);
	// (void)x;
	// (void)y;
	data = (t_data *)param;
	if (x <= WINDOW_WIDTH / 2 - 50)
	{
		data->player->dirX -= 0.02;
		// data->player->planeX -= 0.02;
	}
	// if (y <= WINDOW_HEIGHT / 2 - 100)
	// {sssa
	// 	data->player->dirY -= 0.02;
	// 	// data->player->planeX -= 0.02;
	// }
	
	if (x >= WINDOW_WIDTH / 2 + 50)
	{
		data->player->dirX += 0.02;
		// data->player->planeX += 0.02;
	}
	raycasting(data, data->mlx, data->game, data->player);
	return (0);
}

int	key_action(int key, t_data *data)
{

	printf("%d\n", key);
	if (key == 97)
	{
		if ((data->map->map)[(int)(data->player->posX - 0.2)][(int)data->player->posY] != '1')
			data->player->posX -= 0.1;
	}
	if (key == 100)
	{
		if ((data->map->map)[(int)(data->player->posX + 0.2)][(int)data->player->posY] != '1')
			data->player->posX += 0.1;
	}
	if (key == 119)
	{
		if ((data->map->map)[(int)(data->player->posX)][(int)(data->player->posY + 0.2)] != '1')
			data->player->posY += 0.1;
	}
	if (key == 115)
	{
		if ((data->map->map)[(int)(data->player->posX)][(int)(data->player->posY - 0.2)] != '1')
			data->player->posY -= 0.1;
	}
	raycasting(data, data->mlx, data->game, data->player);
	return (0);
}


void init_mlx(t_data *data)
{
	data->mlx->mlx = mlx_init();
	if (!data->mlx->mlx)
		return ;
	data->mlx->win = mlx_new_window(data->mlx->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	data->mlx->img = mlx_new_image(data->mlx->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img,
			&data->mlx->bits_per_pixel, &data->mlx->line_length, &data->mlx->endian);
	raycasting(data, data->mlx, data->game, data->player);
	
	mlx_hook(data->mlx->win, 6, PointerMotionMask, mouse_move, data);
	mlx_key_hook(data->mlx->win, key_action, data);
	mlx_mouse_hook(data->mlx->win, mouse_hook, data);
	// mlx_mouse_move(data->mlx->mlx, data->mlx->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

	
	// mlx_hook(data->mlx->win, 500, 0, mouse_move_right, data);
	// mlx_hook(data->mlx->win, 17, 0, on_destroy_event, data);
	mlx_loop(data->mlx->mlx);

}
