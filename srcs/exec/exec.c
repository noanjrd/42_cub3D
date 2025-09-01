/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:35:40 by njard             #+#    #+#             */
/*   Updated: 2025/09/01 18:30:06 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	mouse_hook(int button, int x, int y, void *param)
{
	t_data	*data;

	printf("%d\n", button);

	// printf("%d\n", x);
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


	// printf("%d\n", x);
	// (void)x;
	// (void)y;
	double oldDirX;
	double oldPlaneX;
	double Degree;

	Degree = 0.03;
	data = (t_data *)param;
	oldDirX = data->player->dirX;
	oldPlaneX = data->player->planeX;

	if (x >= (WINDOW_WIDTH / 3) * 2 )
	{
		data->player->dirX = data->player->dirX * cos(Degree) - data->player->dirY * sin(Degree);
		data->player->dirY = oldDirX * sin(Degree) + data->player->dirY * cos(Degree);
		data->player->planeX = data->player->planeX * cos(Degree) - data->player->planeY * sin(Degree);
		data->player->planeY = oldPlaneX * sin(Degree) + data->player->planeY * cos(Degree);
	}
	if (x <= WINDOW_WIDTH / 3)
	{
		data->player->dirX = data->player->dirX * cos(-Degree) - data->player->dirY * sin(-Degree);
		data->player->dirY = oldDirX * sin(-Degree) + data->player->dirY * cos(-Degree);
		data->player->planeX = data->player->planeX * cos(-Degree) - data->player->planeY * sin(-Degree);
		data->player->planeY = oldPlaneX * sin(-Degree) + data->player->planeY * cos(-Degree);
	}
	raycasting(data, data->mlx, data->game, data->player);
	return (0);
}

int	key_action(int key, t_data *data)
{

	double oldDirX = data->player->dirX;
	double oldPlaneX = data->player->planeX;
	printf("%d\n", key);
	if (key == 97)
	{
		if ((data->map->map)[(int)(data->player->posY - data->player->planeY *0.1)][(int)(data->player->posX - data->player->planeX * 0.1)] != '1')
		{
			data->player->posX -= data->player->planeX * 0.1;
			data->player->posY -= data->player->planeY *0.1;
		}
	}
	if (key == 100)
	{
		if ((data->map->map)[(int)(data->player->posY + data->player->planeY *0.1)][(int)(data->player->posX + data->player->planeX * 0.1)] != '1')
		{
			data->player->posX += data->player->planeX * 0.1;
			data->player->posY += data->player->planeY *0.1;
		}
	}
	if (key == 119)
	{
		if ((data->map->map)[(int)(data->player->posY + data->player->dirY *0.1)][(int)(data->player->posX + data->player->dirX * 0.1)] != '1')
		{
			data->player->posX += data->player->dirX * 0.1;
			data->player->posY += data->player->dirY *0.1;
		}
	}
	if (key == 115)
	{
		if ((data->map->map)[(int)(data->player->posY - data->player->dirY *0.1)][(int)(data->player->posX - data->player->dirX * 0.1)] != '1')
		{
			data->player->posX -= data->player->dirX * 0.1;
			data->player->posY -= data->player->dirY *0.1;
		}
	}
	if (key == 65363)
	{
		data->player->dirX = data->player->dirX * cos(0.5) - data->player->dirY * sin(0.5);
		data->player->dirY = oldDirX * sin(0.5) + data->player->dirY * cos(0.5);
		data->player->planeX = data->player->planeX * cos(0.5) - data->player->planeY * sin(0.5);
		data->player->planeY = oldPlaneX * sin(0.5) + data->player->planeY * cos(0.5);
	}
	if (key == 65361)
	{
		data->player->dirX = data->player->dirX * cos(-0.5) - data->player->dirY * sin(-0.5);
		data->player->dirY = oldDirX * sin(-0.5) + data->player->dirY * cos(-0.5);
		data->player->planeX = data->player->planeX * cos(-0.5) - data->player->planeY * sin(-0.5);
		data->player->planeY = oldPlaneX * sin(-0.5) + data->player->planeY * cos(-0.5);
	}
	if (key == 65307)
	{
		ft_destroy_window(data);
		return 0;
	}
	raycasting(data, data->mlx, data->game, data->player);
	return (0);
}

void	ft_create_texture(t_data *data)
{
	t_texture *NO;
	t_texture *WE;
	t_texture *EA;
	t_texture *SO;
	NO = malloc(sizeof(t_texture));
	WE = malloc(sizeof(t_texture));
	EA = malloc(sizeof(t_texture));
	SO = malloc(sizeof(t_texture));
	if (!NO || !WE || !EA || !SO)
		return; 


	data->EA = EA;
	data->SO = SO;
	data->NO = NO;
	data->WE = WE;
	data->NO->img = mlx_xpm_file_to_image(data->mlx->mlx, data->NO_texture , &data->NO->width, &data->NO->height);
	data->NO->addr = mlx_get_data_addr(data->NO->img, &data->NO->bits_per_pixel, &data->NO->line_length, &data->NO->endian);

	data->EA->img = mlx_xpm_file_to_image(data->mlx->mlx, data->EA_texture , &data->EA->width, &data->EA->height);
	data->EA->addr = mlx_get_data_addr(data->EA->img, &data->EA->bits_per_pixel, &data->EA->line_length, &data->EA->endian);

	data->WE->img = mlx_xpm_file_to_image(data->mlx->mlx, data->WE_texture , &data->WE->width, &data->WE->height);
	data->WE->addr = mlx_get_data_addr(data->WE->img, &data->WE->bits_per_pixel, &data->WE->line_length, &data->WE->endian);

	data->SO->img = mlx_xpm_file_to_image(data->mlx->mlx, data->SO_texture , &data->SO->width, &data->SO->height);
	data->SO->addr = mlx_get_data_addr(data->SO->img, &data->SO->bits_per_pixel, &data->SO->line_length, &data->SO->endian);
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
	ft_create_texture(data);
	raycasting(data, data->mlx, data->game, data->player);
	
	mlx_hook(data->mlx->win, 6, PointerMotionMask, mouse_move, data);
	mlx_key_hook(data->mlx->win, key_action, data);
	mlx_mouse_hook(data->mlx->win, mouse_hook, data);
	mlx_hook(data->mlx->win, 17, 0, ft_destroy_window, data);
	// mlx_mouse_move(data->mlx->mlx, data->mlx->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

	
	// mlx_hook(data->mlx->win, 500, 0, mouse_move_right, data);
	// mlx_hook(data->mlx->win, 17, 0, on_destroy_event, data);
	mlx_loop(data->mlx->mlx);

}
