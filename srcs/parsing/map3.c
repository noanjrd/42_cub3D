/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:04:57 by njard             #+#    #+#             */
/*   Updated: 2025/07/31 13:31:24 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void fill_line(t_map *map, int z, int start, int end)
{
	int i;
	int h;

	h = 0;
	i = start;
	while (h <= end)
	{
		map->map[z][i++] = map->l[h++];
		if (map->l[h] == ' ' || (map->l[h] >= 7 && map->l[h] <= 13))
		{
			while (map->l[h] && map->l[h] != '1' && map->l[h] != '0' &&
				map->l[h] != 'W' && map->l[h] != 'S' && map->l[h] != 'E' &&
				map->l[h] != 'N')
			{
				map->map[z][i++] = 'X';
				h++;
			}
		}
	}
	while (h <= map->map_length)
	{
		map->map[z][i++] = 'X';
		h++;
	}
	map->map[z][i] = 0;
}
