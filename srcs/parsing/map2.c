/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:04:57 by njard             #+#    #+#             */
/*   Updated: 2025/07/28 12:09:36 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int copy_line_map(t_map *map, char *line, int z, int i)
{
	int j;
	int h;

	if (line[i] == '\n')
		return 0;
	j = i;
	while (line[j] && line[j] != '\n')
		j++;
	j--;
	while (line[j] && (line[j] == ' ' || (line[j] >= 7 && line[j] <= 13)))
		j--;
	map->map[z] = malloc((j + 4 + (map->map_length - j)) * sizeof(char));
	if (!map->map[z])
		return 1;
	map->map[z][0] = 'X';
	h = 0;
	i = 1;
	while (line[h] && (line[h] == ' ' || (line[h] >= 7 && line[h] <= 13)))
	{
		map->map[z][i++] =  'X';
		h++;
	}
	h = h;
	map->map[z][0] = 'X';
	while(h <= j)
	{
		map->map[z][i++] = line[h++];
		if (line[h - 1] && line[h - 1] == '1' && (line[h] == ' ' ||
			(line[h] >= 7 && line[h] <= 13)))
		{	
			while(line[h] && line[h] != '1' && line[h] != '0' &&
				line[h] != 'W' && line[h] != 'S' &&
				line[h] != 'E' && line[h] != 'N')
			{
				map->map[z][i++] = 'X';
				h++;
			}
		}
	}
	while(h <= map->map_length)
	{
		map->map[z][i++] = 'X';
		h++;
	}
	map->map[z][i] = 0;
	i = 0;
	while (line && line[i])
	{
		if (line[i] == 'S' || line[i] == 'W' ||
			line[i] == 'E' || line[i] == 'N')
			map->nb_player++;
		i++;
	}
	return 0;
}
