/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:04:57 by njard             #+#    #+#             */
/*   Updated: 2025/07/15 16:06:40 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int copy_line_map(t_map *map, char *line, int z)
{
	int i;
	int j;
	int h;

	i = 0;
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
		if (line[h - 1] && line[h - 1] == '1' && (line[h] == ' ' || (line[h] >= 7 && line[h] <= 13)))
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
		if (line[i] == 'S' || line[i] == 'W' || line[i] == 'E' || line[i] == 'N')
			map->nb_player++;
		i++;
	}
	return 0;
}

int skip_old_line(char *line)
{
	int i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] == ' ' || (line[i] >= 7 && line[i] <= 13))
		i++;
	if (line[i] == '1')
		return (1);
	return (0);
}

void	put_X_to_line(t_map *map, char *line, int z)
{
	int i;
	int len;

	i = 0;
	len = map->map_length + 2;
	map->map[z] = malloc((len + 1) * sizeof(char));
	while(i < len)
	{
		map->map[z][i] = 'X';
		i++;
	}
	map->map[z][i] = 0;
	if (z == (map->map_height + 1))
	{
		line = map->map[z + 1] = NULL;
	}
	i = 0;
	return ;
}

void get_line_map(t_map *map, int fd)
{
	char *line;
	int z;

	z = 1;
	line = get_next_line(fd);
	while (line && skip_old_line(line) == 0)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line)
	{
		put_X_to_line(map, line, 0);
		copy_line_map(map, line, z);
	}
	while (line)
	{
		free(line);
		z++;
		line = get_next_line(fd);
		if (line)
			copy_line_map(map, line, z);
	}
	put_X_to_line(map, line, (map->map_height + 1));
	ft_print_tab(map->map);
}

void get_map_next(t_map *map)
{
	int fd2;
	int fd3;

	fd2 = open(map->map_file, O_RDONLY, 0700);
	if (ft_check_map_error(map, fd2) == -1)
	{
		map->map[0] = NULL;
		return (ft_print_error("There is an error regarding the map."));
	}
	fd3 = open(map->map_file, O_RDONLY, 0700);
	get_line_map(map, fd3);
	if (map->nb_player == 0 || map->nb_player >= 2)
		return (ft_print_error("The number of players is incorrect."));
	close(fd2);
}

void	get_map(t_map *map, int fd)
{
	char *line;
	
	line = get_next_line(fd);
	if (line)
		map->map_height++;
	while (line && skip_old_line(line) == 0)
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && ft_strcmp_space(line, "1") == 1)
			map->map_height++;
	}
	(map->map) = malloc((map->map_height + 3) * sizeof(char *));
	get_map_next(map);
}

