/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:35:40 by njard             #+#    #+#             */
/*   Updated: 2025/09/04 13:22:25 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	set_mlx_texture(t_data *data, t_texture *tex, char *texture_file)
{
	tex->img = mlx_xpm_file_to_image(data->mlx->mlx,
			texture_file,
			&tex->width,
			&tex->height);
	tex->addr = mlx_get_data_addr(tex->img,
			&tex->bits_per_pixel,
			&tex->line_length,
			&tex->endian);
}

void	ft_create_texture(t_data *data)
{
	t_texture	*no;
	t_texture	*we;
	t_texture	*ea;
	t_texture	*so;

	no = malloc(sizeof(t_texture));
	we = malloc(sizeof(t_texture));
	ea = malloc(sizeof(t_texture));
	so = malloc(sizeof(t_texture));
	if (!no || !we || !ea || !so)
		return ;
	data->ea = ea;
	data->so = so;
	data->no = no;
	data->we = we;
	set_mlx_texture(data, data->ea, data->ea_texture);
	set_mlx_texture(data, data->so, data->so_texture);
	set_mlx_texture(data, data->no, data->no_texture);
	set_mlx_texture(data, data->we, data->we_texture);
}

void	init_mlx(t_data *data)
{
	data->mlx->mlx = mlx_init();
	if (!data->mlx->mlx)
		return ;
	data->mlx->win = mlx_new_window(data->mlx->mlx,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			"cub3D");
	data->mlx->img = mlx_new_image(data->mlx->mlx,
			WINDOW_WIDTH,
			WINDOW_HEIGHT);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img,
			&data->mlx->bits_per_pixel,
			&data->mlx->line_length,
			&data->mlx->endian);
	ft_create_texture(data);
	mlx_hook(data->mlx->win, 6, PointerMotionMask, mouse_move, data);
	mlx_hook(data->mlx->win, 17, 0, ft_destroy_window, data);
	mlx_mouse_hook(data->mlx->win, mouse_hook, data);
	mlx_key_hook(data->mlx->win, key_action, data);
	mlx_loop_hook(data->mlx->mlx, raycasting, data);
	mlx_loop(data->mlx->mlx);
	return ;
}
