/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:25:42 by njard             #+#    #+#             */
/*   Updated: 2025/09/04 13:47:44 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_init_mlx(t_mlx *mlx)
{
	mlx->addr = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->mlx = NULL;
}

void	ft_init_map(t_map *map, char **argv)
{
	map->map_file = argv[1];
	map->map_height = 0;
	map->map_length = 0;
	map->nb_player = 0;
	map->map = NULL;
}

void	ft_init_game(t_game *game)
{
	game->deltadistx = 0;
	game->deltadisty = 0;
	game->raydirx = 0;
	game->raydiry = 0;
	game->drawend = 0;
	game->drawstart = 0;
	game->lineheight = 0;
	game->texx = 0;
	game->texpos = 0;
	game->texcolor = 0;
	game->stepy = 0;
	game->stepx = 0;
	game->step = 0;
	game->side = 0;
}
