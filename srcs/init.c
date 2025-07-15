/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:25:42 by njard             #+#    #+#             */
/*   Updated: 2025/07/15 15:59:23 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_init_map(t_map *map, char **argv)
{
	map->map_file = argv[1];
	map->map_height = 0;
	map->map_length = 0;
	map->nb_player = 0;
	map->map = NULL;
}

void	ft_init_data(t_data *data, char **argv)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	data->NO_texture = NULL;
	data->WE_texture = NULL;
	data->EA_texture = NULL;
	data->SO_texture = NULL;
	data->F_color = NULL;
	data->C_color = NULL;
	data->map = map;
	ft_init_map(map, argv);
	return ;
}
