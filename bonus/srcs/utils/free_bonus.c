/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:17:35 by njard             #+#    #+#             */
/*   Updated: 2025/09/04 12:01:13 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	return ;
}

void	ft_free_mlx(t_mlx *mlx)
{
	free(mlx->mlx);
	free(mlx);
	return ;
}

void	ft_free_texture(t_mlx *mlx, t_texture *tex)
{
	mlx_destroy_image(mlx->mlx, tex->img);
	free(tex);
	return ;
}

int	ft_destroy_window(t_data *data)
{
	ft_free_texture(data->mlx, data->ea);
	ft_free_texture(data->mlx, data->we);
	ft_free_texture(data->mlx, data->no);
	ft_free_texture(data->mlx, data->so);
	mlx_destroy_image(data->mlx->mlx, data->mlx->img);
	mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	mlx_loop_end(data->mlx->mlx);
	mlx_destroy_display(data->mlx->mlx);
	ft_free_data(data);
	exit(0);
	return (0);
}

void	ft_free_data(t_data *data)
{
	free(data->c_color);
	free(data->f_color);
	free(data->no_texture);
	free(data->so_texture);
	free(data->we_texture);
	free(data->ea_texture);
	free(data->floor);
	free(data->ceiling);
	free(data->game);
	free(data->player);
	ft_free_tab(data->map->map);
	free(data->map);
	ft_free_mlx(data->mlx);
	free(data);
}
