/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:04:57 by njard             #+#    #+#             */
/*   Updated: 2025/07/14 17:13:23 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int copy_line_map(t_data *data, char *line, int z)
{
	int i;
	int j;
	int h;

	i = 0;
	if (line[i] == '\n')
		return 0;
	while (line[i] && (line[i] == ' ' || (line[i] >= 7 && line[i] <= 13)))
		i++;
	j = i;
	while (line[j] && line[j] != '\n')
		j++;
	j--;
	while (line[j] && (line[j] == ' ' || (line[j] >= 7 && line[j] <= 13)))
		j--;
	data->map[z] = malloc((j + 3 + (data->map_length - j)) * sizeof(char));
	if (!data->map[z])
		return 1;
	h = i;
	i = 1;
	data->map[z][0] = 'X';
	while(h <= j)
	{
		data->map[z][i++] = line[h++];
	}
	while(h <= data->map_length)
	{
		data->map[z][i++] = 'X';
		h++;
	}
	data->map[z][i] = 0;
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

void	put_X_to_line(t_data *data, char *line, int z)
{
	int i;
	int len;

	i = 0;
	len = data->map_length + 2;
	data->map[z] = malloc((len + 1) * sizeof(char));
	while(i < len)
	{
		data->map[z][i] = 'X';
		i++;
	}
	data->map[z][i] = 0;
	if (z == (data->map_height + 1))
	{
		line = data->map[z + 1] = NULL;
	}
	return ;
}

void get_line_map(t_data *data, int fd)
{
	char *line;
	int z;

	z = 1;
	line = get_next_line(fd);
	while (line && skip_old_line(line) == 0)
	{
		free(line);
		line = get_next_line(fd);
		// if (line)
			// printf("%s", line);
	}
	if (line)
	{
		put_X_to_line(data, line, 0);
		copy_line_map(data, line, z);
	}
	// printf("%s\n", line);
	while (line)
	{
		free(line);
		z++;
		line = get_next_line(fd);
		if (line)
		{
			// printf("wqqqq: %s", line);
			copy_line_map(data, line, z);
		}

	}
	put_X_to_line(data, line, (data->map_height + 1));
	ft_print_tab(data->map);
	return ;
}

int	get_map(t_data *data, int fd)
{
	char *line;
	int fd2;
	int fd3;
	
	line = get_next_line(fd);
	// printf("tuuuuu : %s\n", line);
	if (line)
		data->map_height++;
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
		{
			// printf("%s\n", line);
			data->map_height++;
		}
	}
	(data->map) = malloc((data->map_height + 3) * sizeof(char *));
	fd2 = open(data->map_file, O_RDONLY, 0700);
	if (fd2 < 0)
	{
		ft_print_error("Erreur d'ouverture du fichier");
		return (1);
	}
	if (ft_check_map_error(data, fd2) == 1)
	{
		ft_print_error("Ya une erreur");
		data->map[0] = NULL;
		return 1;
	}
	fd3 = open(data->map_file, O_RDONLY, 0700);
	get_line_map(data, fd3);
	printf("length : %d\n", data->map_length);
	printf("height : %d\n", data->map_height);
	close(fd);
	close(fd2);
	// printf("error : %d\n", check_respect_format(data));
	return (0);
}

