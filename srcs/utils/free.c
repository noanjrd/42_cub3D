/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:17:35 by njard             #+#    #+#             */
/*   Updated: 2025/09/01 11:13:04 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void ft_free_tab(char **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while(tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	return ;
}

void ft_free_mlx(t_mlx *mlx)
{
	// free(mlx->addr);
	free(mlx->mlx);
	free(mlx);
	return ;
}

void ft_free_map(t_map *map)
{
	ft_free_tab(map->map);
	free(map);
	return ;
}

int ft_destroy_window(t_data *data)
{
	mlx_destroy_image(data->mlx->mlx, data->mlx->img);
	mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	mlx_loop_end(data->mlx->mlx);
	mlx_destroy_display(data->mlx->mlx);
	ft_free_data(data);
	exit(0);
	return 0;
}

void	ft_free_texture(t_texture *tex)
{
	// mlx_destroy_image(data->mlx->mlx, data->mlx->img);
	// mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	// mlx_loop_end(data->mlx->mlx);
	// mlx_destroy_display(data->mlx->mlx);
	free(tex->img);
	// free(tex->addr);
	free(tex);
}

void ft_free_data(t_data *data)
{
	free(data->C_color);
	free(data->F_color);
	free(data->NO_texture);
	free(data->SO_texture);
	free(data->WE_texture);
	free(data->EA_texture);
	free(data->floor);
	free(data->ceiling);
	free(data->game);
	free(data->player);
	ft_free_map(data->map);
	ft_free_mlx(data->mlx);
	ft_free_texture(data->EA);
	ft_free_texture(data->WE);
	ft_free_texture(data->NO);
	ft_free_texture(data->SO);
	free(data);
}
