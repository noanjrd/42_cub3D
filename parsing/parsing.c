/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:39:03 by njard             #+#    #+#             */
/*   Updated: 2025/07/13 13:54:52 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

char *ft_copy_info(char *line)
{
	int i;
	int j;
	char *new;

	i = 0;
	while (line[i] && (line[i] == ' ' || (line[i] >= 7 && line[i] <= 13)))
		i++;
	i+= 2;
	while (line[i] && (line[i] == ' ' || (line[i] >= 7 && line[i] <= 13)))
		i++;
	j = i;
	while (line[j] && !(line[j] == ' ' || (line[j] >= 7 && line[j] <= 13)))
		j++;
	new = malloc((j - i + 1) * sizeof(char));
	j = i;
	i = 0;
	while (line[j] && !(line[j] == ' ' || (line[j] >= 7 && line[j] <= 13)))
		new[i++] = line[j++];
	new[i] = 0;
	return (new);
} 

void	get_map(t_data *data, char *line)
{
	return ;
}

void	check_info(t_data *data, char *line)
{
	int i;

	i = 0;
	while (line && line[i] && (line[i] == ' ' ||
			(line[i] >= 7 && line[i] <= 13)))
		i++;
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
	if (line[i] == '1')
	{
		get_map(data, line);
	}
}

void get_info(t_data *data, int fd)
{
	char *line;
	line = get_next_line(fd);
	printf("%s\n", line);
	if (line)
		check_info(data, line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		printf("%s\n", line);
		check_info(data, line);
	}
	return ;
}

int	check_error_parsing(t_data *data)
{
	if (!data->F_color || !data->C_color || !data->NO_texture ||
		!data->SO_texture || !data->EA_texture || !data->WE_texture)
		ft_print_error("One of the parameters required is not correct");
		return (1);
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
	get_info(data, fd);
	// check_error_parsing(data);
}
