/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:25:42 by njard             #+#    #+#             */
/*   Updated: 2025/09/04 12:01:44 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	player_direction_rest(t_player *player, char direction)
{
	if (direction == 'W')
	{
		player->dirx = -1;
		player->diry = 0;
		player->planex = 0;
		player->planey = -0.66;
	}
	if (direction == 'E')
	{
		player->dirx = 1;
		player->diry = 0;
		player->planex = 0;
		player->planey = 0.66;
	}
}

void	player_direction(t_player *player, char direction)
{
	if (direction == 'N')
	{
		player->dirx = 0;
		player->diry = -1;
		player->planex = 0.66;
		player->planey = 0;
	}
	if (direction == 'S')
	{
		player->dirx = 0;
		player->diry = 1;
		player->planex = -0.66;
		player->planey = 0;
	}
	player_direction_rest(player, direction);
}

void	ft_init_player(t_player *player, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
			{
				player->posx = j + 0.5;
				player->posy = i + 0.5;
				player_direction(player, map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_init_data_rest(t_data *data, char **argv)
{
	t_player	*player;
	t_game		*game;

	player = malloc(sizeof(t_player));
	game = malloc(sizeof(t_game));
	data->game = game;
	data->player = player;
	ft_init_mlx(data->mlx);
	ft_init_game(data->game);
	ft_init_map(data->map, argv);
}

void	ft_init_data(t_data *data, char **argv)
{
	t_map	*map;
	t_color	*ceiling;
	t_color	*floor;
	t_mlx	*mlx;

	map = malloc(sizeof(t_map));
	mlx = malloc(sizeof(t_mlx));
	ceiling = malloc(sizeof(t_color));
	floor = malloc(sizeof(t_color));
	data->no_texture = NULL;
	data->we_texture = NULL;
	data->ea_texture = NULL;
	data->so_texture = NULL;
	data->f_color = NULL;
	data->c_color = NULL;
	data->map = map;
	data->ceiling = ceiling;
	data->floor = floor;
	data->mlx = mlx;
	ft_init_data_rest(data, argv);
}
