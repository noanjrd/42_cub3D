/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:17:35 by njard             #+#    #+#             */
/*   Updated: 2025/07/16 14:38:42 by njard            ###   ########.fr       */
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

void ft_free_map(t_map *map)
{
	ft_free_tab(map->map);
	free(map);
	return ;
}

void ft_free_data(t_data *data)
{
	int i;
	free(data->C_color);
	free(data->F_color);
	free(data->NO_texture);
	free(data->SO_texture);
	free(data->WE_texture);
	free(data->EA_texture);
	free(data->floor);
	free(data->ceiling);
	ft_free_map(data->map);
	free(data);
}
