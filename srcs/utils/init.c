/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:25:42 by njard             #+#    #+#             */
/*   Updated: 2025/09/01 11:25:30 by njard            ###   ########.fr       */
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

void	ft_init_game(t_game *game)
{
	game->deltaDistX = 0;
	game->cameraX = 0;
	game->deltaDistY = 0;
	game->rayDirX = 0;
	game->rayDirY = 0;
}

void	player_direction( t_player *player, char direction) // ici par convention les y sont inverse car on prend le systeme d affichage d une fentre ou tout en haut et 0,0 et eb bas 0,-1
{
	if (direction == 'N')
	{
		player->dirX = 0;
		player->dirY = -1;
		player->planeX = 0.66; // le plane est perpendiculaire au vectrueur de directiion et est sur un repere orthonorme lui, de plus on prend le vecteur de fov a droite de l ecran pour le plane
		player->planeY = 0;

	}
	if (direction == 'S')
	{
		player->dirX = 0;
		player->dirY = 1;
		player->planeX = -0.66;
		player->planeY = 0;
	}
	if (direction == 'W')
	{
		player->dirX = -1;
		player->dirY = 0;
		player->planeX = 0;
		player->planeY = -0.66;
	}
	if (direction == 'E')
	{
		player->dirX = 1;
		player->dirY = 0;
		player->planeX = 0;
		player->planeY = 0.66;
	}
}

void	ft_init_player( t_player *player, char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
			{
				player->posX = j + 0.5;
				player->posY = i + 0.5 ;
				player_direction(player, map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
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
	t_game *game;

	map = malloc(sizeof(t_map));
	mlx = malloc(sizeof(t_mlx));
	ceiling = malloc(sizeof(t_color));
	floor = malloc(sizeof(t_color));
	player = malloc(sizeof(t_player));
	game = malloc(sizeof(t_game));
	data->NO_texture = NULL;
	data->WE_texture = NULL;
	data->EA_texture = NULL;
	data->SO_texture = NULL;
	data->F_color = NULL;
	data->C_color = NULL;
	data->map = map;
	data->ceiling  =ceiling;
	data->floor = floor;
	data->mlx = mlx;
	data->game = game;
	data->player = player;
	ft_init_game(data->game);
	ft_init_map(map, argv);
	return ;
}
