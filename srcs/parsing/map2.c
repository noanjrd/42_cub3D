/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:04:57 by njard             #+#    #+#             */
/*   Updated: 2025/07/29 14:26:19 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int skip_trailing_whitespace(char *line, int i)
{
	while (line[i] && line[i] != '\n')
		i++;
	i--;
	while (line[i] && (line[i] == ' ' || (line[i] >= 7 && line[i] <= 13)))
		i--;
	return i;
}

static int allocate_map_line(t_map *map, int z, int j)
{
	map->map[z] = malloc((j + 4 + (map->map_length - j)) * sizeof(char));
	if (!map->map[z])
		return -1;
	return (0);
}

static int fill_prefix(t_map *map, char *line, int z)
{
	int h;
	int i;

	h = 0;
	i = 1;
	map->map[z][0] = 'X';
	while (line[h] && (line[h] == ' ' || (line[h] >= 7 && line[h] <= 13)))
	{
		map->map[z][i++] = 'X';
		h++;
	}
	return i;
}

static void fill_line(t_map *map, int z, int start, int end)
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

static void count_player(char *line, t_map *map)
{
	int i = 0;
	while (line[i])
	{
		if (line[i] == 'S' || line[i] == 'W' ||
			line[i] == 'E' || line[i] == 'N')
			map->nb_player++;
		i++;
	}
}

int copy_line_map(t_map *map, char *line, int z, int i)
{
	int j;
	int start;

	if (line[i] == '\n')
		return 0;
	j = skip_trailing_whitespace(line, i);
	if (allocate_map_line(map, z, j) == -1)
		return -1;
	start = fill_prefix(map, line, z);
	map->l = line;
	fill_line(map, z, start, j);
	count_player(line, map);
	return 0;
}
