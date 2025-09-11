/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinguet <mpinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 10:57:45 by njard             #+#    #+#             */
/*   Updated: 2025/08/19 18:04:40 by mpinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int main(int argc, char **argv)
{
	t_data *data;

	if (argc == 1)
		return (ft_print_error("Miss an argument"),0);
	if (argc > 2)
		return (ft_print_error("Too many arguments"),0);
	data = malloc(sizeof(t_data));
	ft_init_data(data, argv);
	if (parsing(data) == 0)
	{
		init_mlx(data);
		init_player(data);
		init_texture(data);
		mlx_hook(data->mlx->win, 17, 0, close_window, data);
		mlx_hook(data->mlx->win , 2, 1L << 0, manage_window, data);
		mlx_key_hook(data->mlx->win, key_action, data);
		mlx_loop_hook(data->mlx->mlx, calcul_display, data);
		mlx_loop(data->mlx->mlx);
	}
	ft_free_data(data);
	return 0;
}
