/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinguet <mpinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:58:24 by njard             #+#    #+#             */
/*   Updated: 2025/09/16 17:31:51 by mpinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	check_length_line(t_map *map, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	while (line[j] && line[j] != '\n')
		j++;
	j--;
	while ((line[j] == ' ' || (line[j] >= 7 && line[j] <= 13)))
		j--;
	if (j - i + 1 > map->map_length)
	{
		map->map_length = j - i + 1;
	}
	return ;
}

int	check_line_format_next(char *line, int z, int i, int j)
{
	i = 0;
	while (line[i] && (line[i] == ' ' || (line[i] >= 7 && line[i] <= 13)))
		i++;
	if (line[i] != '1')
		return (-1);
	j = i;
	while (line[j] && line[j] != '\n')
		j++;
	j--;
	while ((line[j] == ' ' || (line[j] >= 7 && line[j] <= 13)))
		j--;
	while (i <= j)
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'E' && line[i] != 'S'
			&& line[i] != 'W' && line[i] != 'N' && line[i] != ' '
			&& !(line[i] >= 7 && line[i] <= 13))
			return (-1);
		i++;
	}
	if (line[i - 1] != '1')
		return (-1);
	return (0);
}

int	check_line_format(t_map *map, char *line, int z, int i)
{
	int	j;

	if (line[i] == '\n')
		return (0);
	while (line[i] && (line[i] == ' ' || (line[i] >= 7 && line[i] <= 13)))
		i++;
	j = i;
	while (line[j] && line[j] != '\n')
		j++;
	j--;
	while ((line[j] == ' ' || (line[j] >= 7 && line[j] <= 13)))
		j--;
	if (z == 0 || z == map->map_height - 1)
	{
		while (i <= j)
		{
			if (line[i] != '1' && line[i] != ' ' && !(line[i] >= 7
					&& line[i] <= 13))
				return (-1);
			i++;
		}
	}
	check_length_line(map, line);
	return (check_line_format_next(line, z, 0, 0));
}

int	ft_check_map_error(t_map *map, int fd)
{
	char	*line;
	int		z;
	int		error;

	z = 0;
	error = 0;
	line = get_next_line(fd);
	while (line && skip_old_line(line) == 0)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		error = check_line_format(map, line, 0, 0);
	while (line)
	{
		free(line);
		z++;
		line = get_next_line(fd);
		if (line && error == 0)
			error = check_line_format(map, line, z, 0);
	}
	return (error);
}
