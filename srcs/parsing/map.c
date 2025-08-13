/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:04:57 by njard             #+#    #+#             */
/*   Updated: 2025/07/31 13:28:02 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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

void	put_x_to_line(t_map *map, char *line, int z)
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
		put_x_to_line(map, line, 0);
		copy_line_map(map, line, z, 0);
	}
	while (line)
	{
		free(line);
		z++;
		line = get_next_line(fd);
		if (line)
			copy_line_map(map, line, z, 0);
	}
	put_x_to_line(map, line, (map->map_height + 1));
	// ft_print_tab(map->map);
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

