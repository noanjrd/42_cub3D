/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:35:40 by njard             #+#    #+#             */
/*   Updated: 2025/09/03 20:39:12 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void set_mlx_texture(t_data *data, t_texture *tex, char *texture_file)
{
	tex->img = mlx_xpm_file_to_image(data->mlx->mlx,
				texture_file , &tex->width, &tex->height);
	tex->addr = mlx_get_data_addr(tex->img,
			&tex->bits_per_pixel,
			&tex->line_length, &tex->endian);
}

void	ft_create_texture(t_data *data)
{
	t_texture *NO;
	t_texture	*WE;
	t_texture	*EA;
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
	set_mlx_texture(data, data->EA, data->EA_texture);
	set_mlx_texture(data, data->SO, data->SO_texture);
	set_mlx_texture(data, data->NO, data->NO_texture);
	set_mlx_texture(data, data->WE, data->WE_texture);
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
	mlx_hook(data->mlx->win, 6, PointerMotionMask, mouse_move, data);
	mlx_hook(data->mlx->win, 17, 0, ft_destroy_window, data);
	mlx_mouse_hook(data->mlx->win, mouse_hook, data);
	mlx_key_hook(data->mlx->win, key_action, data);
	mlx_loop_hook(data->mlx->mlx, raycasting, data);
	mlx_loop(data->mlx->mlx);
	return ;
}
