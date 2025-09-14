/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_before_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinguet <mpinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:09:34 by njard             #+#    #+#             */
/*   Updated: 2025/09/14 19:21:42 by mpinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int check_other_character(char *s1, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	while (s1[i] && s1[i] != '\n' && (s1[i] == ' ' ||
			(s1[i] >= 7 && s1[i] <= 13 )))
		i++;
	if (n < 7 && (s1[i] == '1' || s1[i] == '0'))
		return (1);
	if ((s1[i] >= 33 && s1[i] <= 47) ||
		(s1[i] >= 50 && s1[i] <= 127))
		return 1;
	return 0;
}

int check_info_next(t_data *data, char *line, int i)
{
	if (check_string_beggining(line, "WE",1) == 1 || 
		check_string_beggining(line, "NO",1) == 1 || 
		check_string_beggining(line, "EA",1) == 1)
		return 0;
	else if (check_string_beggining(line, "SO",1) == 1)
	{
		if (data->SO_texture)
			return -1;
		data->SO_texture = ft_copy_info(line);
	}
	else if (check_string_beggining(line, "F",0) == 1)
	{
		if (data->F_color)
			return -1;
		data->F_color = ft_copy_info(line);
	}
	else if (check_string_beggining(line, "C",0) == 1)
	{
		if (data->C_color)
			return -1;
		data->C_color = ft_copy_info(line);
	}
	else if (check_other_character(line, i) == 1)
		return (ft_print_error("Wrong texture name or character of map."), -1);
	return 0;
}

int	check_info(t_data *data, char *line, int i)
{
	if (ft_strcmp_space(line, "1") == 1 && 
		check_first_param(data) == 0 && i > 6)
		return -1;
	else if (check_string_beggining(line, "NO",1) == 1)
	{
		if (data->NO_texture)
			return -1;
		data->NO_texture = ft_copy_info(line);
	}
	else if (check_string_beggining(line, "WE",1) == 1)
	{
		if (data->WE_texture)
			return -1;
		data->WE_texture = ft_copy_info(line);
	}
	else if (check_string_beggining(line, "EA",1) == 1)
	{
		if (data->EA_texture)
			return -1;
		data->EA_texture = ft_copy_info(line);
	}
	return (check_info_next(data, line, i));
}

int get_info(t_data *data, int fd)
{
	char *line;
	int error;
	int fd2;
	int i;

	error = 0;
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (texture_valid(line))
			i++;
		if (line && check_info(data, line, i) == -1 && error == 0)
			error = 1;
		free(line);
		line = get_next_line(fd);
	}
	if (error == 1)
		return 1;
	fd2 = open(data->map->map_file, O_RDONLY);
	if (get_map(data->map, fd2) == 1)
		return (1);
	close(fd);
	return 0;
}
