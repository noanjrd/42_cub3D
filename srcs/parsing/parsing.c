/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:39:03 by njard             #+#    #+#             */
/*   Updated: 2025/07/14 17:11:12 by njard            ###   ########.fr       */
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
	if (data->F_color && data->C_color && data->NO_texture &&
		data->SO_texture && data->EA_texture && data->WE_texture)
	{
		return (1);
	}
	return (0);
}

int	check_info(t_data *data, char *line)
{
	// printf("%s", line);
	if (ft_strcmp_space(line, "1") == 1 && check_first_param(data) == 0)
	{
		return 1;
	}
	if (check_string_beggining(line, "NO") == 1)
		data->NO_texture = ft_copy_info(line);
	if (check_string_beggining(line, "WE") == 1)
		data->WE_texture = ft_copy_info(line);
	if (check_string_beggining(line, "EA") == 1)
		data->EA_texture = ft_copy_info(line);
	if (check_string_beggining(line, "SO") == 1)
		data->SO_texture = ft_copy_info(line);
	if (check_string_beggining(line, "F") == 1)
		data->F_color = ft_copy_info(line);
	if (check_string_beggining(line, "C") == 1)
		data->C_color = ft_copy_info(line);
	return (0);
}


int get_info(t_data *data, int fd)
{
	char *line;
	int error;
	int fd2;

	error = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line && check_info(data, line) == 1 && error == 0)
			error = 1;
		free(line);
		line = get_next_line(fd);
		// if (line)
		// {
		// 	printf("%s", line);

		// }
	}
	if (error == 1)
		return 1;
	else
	{
		fd2 = open(data->map_file, O_RDONLY);
		get_map(data, fd2);
	}
	return 0;
}

void parsing(t_data *data)
{
	int fd;

	fd = open(data->map_file, O_RDONLY, 0700);
	if (fd < 0)
	{
		perror("Error");
		return ;
	}
	if (get_info(data, fd) == 1)
		ft_print_error("One of the parameters is not correctly written");
	// check_map_closed();
	close(fd);
	// check_error_parsing(data);
}
