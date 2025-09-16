/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinguet <mpinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:17:35 by njard             #+#    #+#             */
/*   Updated: 2025/09/16 17:33:35 by mpinguet         ###   ########.fr       */
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
	free(mlx);
	return ;
}

void	ft_free_map(t_map *map)
{
	ft_free_tab(map->map);
	free(map);
	return ;
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
	free(data->player);
	free(data->texture);
	ft_free_map(data->map);
	ft_free_mlx(data->mlx);
	free(data);
}
