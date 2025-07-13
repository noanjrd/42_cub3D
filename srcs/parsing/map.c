/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:04:57 by njard             #+#    #+#             */
/*   Updated: 2025/07/13 15:44:27 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void copy_line_map(t_data *data, char *line, int z)
{
	int i;
	int j;

	i = 0;
	printf("$$$$%s",line);
	while (line[i] && (line[i] == ' ' || (line[i] >= 7 && line[i] <= 13)))
		i++;
	j = i;
	while (line[j] && !(line[j] == ' ' || (line[j] >= 7 && line[j] <= 13)))
		j++;
	data->map[z] = malloc((j + 1) * sizeof(char));
	if (!data->map[z])
		return ;
	j = i;
	i = 0;
	while(line[j] && !(line[j] == ' ' || (line[j] >= 7 && line[j] <= 13)))
	{
		data->map[z][i++] = line[j++];
	}
	data->map[z][i] = 0;
	return ;
}

int skip_old_line(char *line)
{
	int i = 0;
	if (!line)
		return (0);
	while (line[i] == ' ' || (line[i] >= 7 && line[i] <= 13))
		i++;
	return (line[i] == '1');
}


void get_line_map(t_data *data, int fd)
{
	char *line;
	int z;

	z = 0;
	line = get_next_line(fd);
	while (line && skip_old_line(line) == 0)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			printf("%s", line);
		// z++;
	}
	if (line)
		copy_line_map(data, line, z);
	// printf("%s\n", line);
	while (line)
	{
		free(line);
		z++;
		line = get_next_line(fd);
		// printf("%s\n", line);
		if (line)
			copy_line_map(data, line, z);
	}
	data->map[z] = NULL;
	ft_print_tab(data->map);
	return ;
}

int	get_map(t_data *data, int fd)
{
	char *line;
	int fd2;

	line = get_next_line(fd);
	// printf("%s\n", line);
	// if (line)
	// 	data->map_height++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			data->map_height++;
			// printf("%s\n", line);
		}
	}
	(data->map) = malloc((data->map_height + 1) * sizeof(char *));
	printf("%d\n", data->map_height);
	// close(fd);
	fd2 = open(data->map_file, O_RDONLY, 0700);
	get_line_map(data, fd2);
	close(fd2);
	return (0);
}
