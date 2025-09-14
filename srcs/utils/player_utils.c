/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinguet <mpinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:52:42 by mpinguet          #+#    #+#             */
/*   Updated: 2025/09/14 19:52:42 by mpinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void init_position(t_data *data)
{
	int x;
	int y;
	char c;

	x = 0;
	while(data->map->map[x])
	{
		y = 0;
		while(data->map->map[x][y])
		{
			c = data->map->map[x][y];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				data->player->spawn = c;
				data->player->x = ((double)y) + 0.5;
				data->player->y = ((double)x) + 0.5;
				return ;
			}
			y++;
		}
		x++;
	}
}

void init_dir(t_data *data)
{
    if (data->player->spawn == 'N')
    {
        data->player->dir_x = 0;
        data->player->dir_y = -1;
    }
    else if (data->player->spawn == 'S')
    {
        data->player->dir_x = 0;
        data->player->dir_y = 1;
    }
    else if (data->player->spawn == 'E')
    {
        data->player->dir_x = 1;
        data->player->dir_y = 0;
    }
    else if (data->player->spawn == 'W')
    {
        data->player->dir_x = -1;
        data->player->dir_y = 0;
    }
    return ;
}

void 	init_plane(t_data *data)
{    
    data->player->plane_x = -data->player->dir_y * 0.66;
    data->player->plane_y = data->player->dir_x * 0.66;
}