/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_before_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:09:34 by njard             #+#    #+#             */
/*   Updated: 2025/07/20 15:06:01 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int check_string_beggining_next(char *s1, int texture)
{
	int i;
	int j;

	i = 2;
	while (s1[i] == ' ' || (s1[i] >= 7 && s1[i] <= 13 ))
		i++;
	i++;
	while (s1[i] && s1[i] != ' ' && !(s1[i] >= 7 && s1[i] <= 13 ))
		i++;
	j = i;
	if (texture == 1 && (s1[j - 1] != 'm' ||
		s1[j - 2] != 'p' || s1[j - 3] != 'x'))
		return 0;
	i++;
	while(s1[i])
	{
		if (texture == 1 && (s1[i] == ' ' ||
			(s1[i] >= 7 && s1[i] <= 13 )))
			return 0;
		i++;
	}
	return 1;
}

int check_string_beggining(char *s1, char *s2, int texture)
{
	int i;

	i = 0;
	if (!s1)
		return (0);
	if (ft_strlen(s1) < ft_strlen(s2))
	{
		return (0);
	}
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (!s1[i] || (s1[i] != ' ' && !(s1[i] >= 7 && s1[i] <= 13 )))
		return (0);
	while(s1[i] && (s1[i] == ' ' || (s1[i] >= 7 && s1[i] <= 13 )))
		i++;
	if (s1[i] == 0)
		return (0);
	return (check_string_beggining_next(s1, texture));
}

int check_other_character(char *s1)
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
	if ((s1[i] >= 33 && s1[i] <= 47) ||
		(s1[i] >= 50 && s1[i] <= 127))
		return 1;
	return 0;
}

int check_info_next(t_data *data, char *line)
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
	else if (check_other_character(line) == 1)
		return -1;
	return 0;
}

int	check_info(t_data *data, char *line)
{
	if (ft_strcmp_space(line, "1") == 1 && 
		check_first_param(data) == 0)
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
	return (check_info_next(data, line));
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
		if (line && check_info(data, line) == -1 && error == 0)
			error = 1;
		free(line);
		line = get_next_line(fd);
	}
	if (error == 1)
		return 1;
	fd2 = open(data->map->map_file, O_RDONLY);
	get_map(data->map, fd2);
	close(fd);
	return 0;
}
