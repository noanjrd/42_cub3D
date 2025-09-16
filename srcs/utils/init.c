/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:25:42 by njard             #+#    #+#             */
/*   Updated: 2025/07/28 13:14:52 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_init_map(t_map *map, char **argv)
{
	map->map_file = argv[1];
	map->map_height = 0;
	map->map_length = 0;
	map->nb_player = 0;
	map->map = NULL;
}

void	ft_init_mlx(t_mlx *mlx)
{
	mlx->addr = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	
}

void	ft_init_data(t_data *data, char **argv)
{
	t_map *map;
	t_color *ceiling;
	t_color *floor;
	t_mlx *mlx;
	t_player *player;
	t_texture *texture;

	map = malloc(sizeof(t_map));
	mlx = malloc(sizeof(t_mlx));
	ceiling = malloc(sizeof(t_color));
	floor = malloc(sizeof(t_color));
	player = malloc(sizeof(t_player));
	texture = malloc(sizeof(t_texture));
	data->no_texture = NULL;
	data->we_texture = NULL;
	data->ea_texture = NULL;
	data->so_texture = NULL;
	data->f_color = NULL;
	data->c_color = NULL;
	data->map = map;
	data->ceiling  =ceiling;
	data->floor = floor;
	data->mlx = mlx;
	data->player = player;
	data->texture = texture;
	ft_init_map(map, argv);
	return ;
}
