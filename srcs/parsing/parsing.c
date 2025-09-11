/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:39:03 by njard             #+#    #+#             */
/*   Updated: 2025/07/31 13:40:17 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

char *ft_copy_info(char *line)
{
	int i;
	int j;
	int z;
	char *new;

	i = 0;
	while (line[i] && (line[i] == ' ' || (line[i] >= 7 && line[i] <= 13)))
		i++;
	i+= 2;
	while (line[i] && (line[i] == ' ' || (line[i] >= 7 && line[i] <= 13)))
		i++;
	j = i;
	while (line[j] && line[j] != '\n')
		j++;
	j--;
	while ((line[i] == ' ' || (line[i] >= 7 && line[i] <= 13)))
		j--;
	new = malloc((j - i + 2) * sizeof(char));
	z = j + 1;
	j = i;
	i = 0;
	while (line[j] && j < z)
		new[i++] = line[j++];
	new[i] = 0;
	return (new);
}

int check_first_param(t_data *data)
{
	if (data->F_color && data->C_color &&
		data->NO_texture && data->SO_texture &&
		data->EA_texture && data->WE_texture)
	{
		return (1);
	}
	return (0);
}

int open_textures(t_data *data)
{
	int fd;

	fd = open(data->NO_texture, O_RDONLY, 0700);
	if (fd < 0)
		return -1;
	close(fd);
	fd = open(data->SO_texture, O_RDONLY, 0700);
	if (fd < 0)
		return -1;
	close(fd);
	fd = open(data->WE_texture, O_RDONLY, 0700);
	if (fd < 0)
		return -1;
	close(fd);
	fd = open(data->EA_texture, O_RDONLY, 0700);
	if (fd < 0)
		return -1;
	close(fd);
	return 0;
}

int check_name_map(t_map *map)
{
	int i;

	i = 0;
	while (map->map_file[i] && map->map_file[i] != '.')
		i++;
	if (map->map_file[i] == 0)
		return -1;
	i++;
	if (!map->map_file[i] || !map->map_file[i + 1] ||
		!map->map_file[i + 2])
		return -1;
	if (map->map_file[i] != 'c' || map->map_file[i + 1] != 'u' ||
			map->map_file[i + 2] != 'b' || map->map_file[i + 3] != 0)
		return -1;
	return 0;
}

int parsing(t_data *data)
{
	int fd;

	if (check_name_map(data->map) == -1)
		return (ft_print_error("Wrong file extension."), -1);
	fd = open(data->map->map_file, O_RDONLY, 0700);
	if (fd < 0)
		return (perror("Error"), -1);
	if (get_info(data, fd) == 1)
		return (close(fd), -1);
	else if (check_map_closed(data->map) == 1)
		return (close(fd), ft_print_error("The map is not closed"), -1);
	close(fd);
	if (color_to_int(data->F_color, data->floor) == -1)
		return (ft_print_error(WRONG_COLOR_FORMAT), -1);
	if (color_to_int(data->C_color, data->ceiling) == -1)
		return (ft_print_error(NOT_RGB), -1);
	if (check_good_format_color(data) == -1)
		return (ft_print_error(NOT_A_BYTE), -1);
	if (open_textures(data) == -1)
		return (ft_print_error("Can't open one of the textures."), -1);
	return 0;
}
