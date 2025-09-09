/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_before_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:09:34 by njard             #+#    #+#             */
/*   Updated: 2025/09/06 14:10:11 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	check_other_character(char *s1)
{
	int	i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i] && s1[i] != '\n' && (s1[i] == ' ' || (s1[i] >= 7
				&& s1[i] <= 13)))
		i++;
	if ((s1[i] >= 33 && s1[i] <= 47) || (s1[i] >= 50))
		return (1);
	return (0);
}

int	check_info_next(t_data *data, char *line)
{
	if (check_string_beggining(line, "WE", 1) == 1
		|| check_string_beggining(line, "NO", 1) == 1
		|| check_string_beggining(line, "EA", 1) == 1)
		return (0);
	else if (check_string_beggining(line, "SO", 1) == 1)
	{
		if (data->so_texture)
			return (-1);
		data->so_texture = ft_copy_info(line);
	}
	else if (check_string_beggining(line, "F", 0) == 1)
	{
		if (data->f_color)
			return (-1);
		data->f_color = ft_copy_info(line);
	}
	else if (check_string_beggining(line, "C", 0) == 1)
	{
		if (data->c_color)
			return (-1);
		data->c_color = ft_copy_info(line);
	}
	else if (check_other_character(line) == 1)
		return (-1);
	return (0);
}

int	check_info(t_data *data, char *line)
{
	if (ft_strcmp_space(line, "1") == 1
		&& check_first_param(data) == 0)
		return (-1);
	else if (check_string_beggining(line, "NO", 1) == 1)
	{
		if (data->no_texture)
			return (-1);
		data->no_texture = ft_copy_info(line);
	}
	else if (check_string_beggining(line, "WE", 1) == 1)
	{
		if (data->we_texture)
			return (-1);
		data->we_texture = ft_copy_info(line);
	}
	else if (check_string_beggining(line, "EA", 1) == 1)
	{
		if (data->ea_texture)
			return (-1);
		data->ea_texture = ft_copy_info(line);
	}
	return (check_info_next(data, line));
}

int	get_info(t_data *data, int fd)
{
	char	*line;
	int		error;
	int		fd2;

	error = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line && check_info(data, line) == -1 && error == 0)
			error = 1;
		free(line);
		line = get_next_line(fd);
	}
	if (error == 1)
		return (1);
	fd2 = open(data->map->map_file, O_RDONLY);
	if (get_map(data->map, fd2) == -1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
