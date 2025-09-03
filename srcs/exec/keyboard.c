/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:05:58 by njard             #+#    #+#             */
/*   Updated: 2025/09/03 21:04:34 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"


int check_wall(char **map, int y, int x)
{
	if (map[y][x] != '1')
	{
		return (0);
	}
	if (map[y + 1][x] && map[y + 1][x] == 'X')
		return 1;
	if (map[y - 1][x] && map[y - 1][x] == 'X')
		return 1;
	if (map[y][x + 1] && map[y][x + 1] == 'X')
		return 1;
	if (map[y][x - 1] && map[y][x - 1] == 'X')
		return 1;
	return 0;
}


void key_action_rest(int key, t_data *data)
{
	if (key == 119 && check_wall(data->map->map, (int)(data->player->posY
			+ data->player->dirY *0.1), (int)(data->player->posX
		+ data->player->dirX * 0.1)) == 0)
	{
		data->player->posX += data->player->dirX * 0.1;
		data->player->posY += data->player->dirY *0.1;
	}
	if (key == 115 && check_wall(data->map->map,(int)(data->player->posY
			- data->player->dirY *0.1), (int)(data->player->posX
		- data->player->dirX * 0.1)) == 0)
	{
		data->player->posX -= data->player->dirX * 0.1;
		data->player->posY -= data->player->dirY *0.1;
	}
	return ;
}

int	key_action(int key, t_data *data)
{
	// printf("%d\n", key);
	if (key == 97 && check_wall(data->map->map, (int)(data->player->posY
			- data->player->planeY * 0.1), (int)(data->player->posX
		- data->player->planeX * 0.1)) == 0)
	{
			data->player->posX -= data->player->planeX * 0.1;
			data->player->posY -= data->player->planeY *0.1;
	}
	if (key == 100 && check_wall(data->map->map, (int)(data->player->posY
			+ data->player->planeY *0.1), (int)(data->player->posX
		+ data->player->planeX * 0.1)) == 0)
	{
		data->player->posX += data->player->planeX * 0.1;
		data->player->posY += data->player->planeY *0.1;
	}
	key_action_rest(key, data);
	if (key == 65363)
		change_direction(data, 0.5);
	if (key == 65361)
		change_direction(data, -0.5);
	if (key == 65307)
		return (ft_destroy_window(data));
	return (0);
}
