/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:39:03 by njard             #+#    #+#             */
/*   Updated: 2025/07/16 14:37:12 by njard            ###   ########.fr       */
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

int	color_to_int(char *color_tab, t_color *color, int j)
{
	int i;
	char *tab;

	i = 0;
	tab = malloc(100);
	while (color_tab[j] && color_tab[j] != ',')
		tab[i++] = color_tab[j++];
	if (color_tab[j] == 0)
		return -1;
	j++;
	tab[i] = 0;
	color->r = ft_atoi(tab);
	i = 0;
	while (color_tab[j] && color_tab[j] != ',')
		tab[i++] = color_tab[j++];
	if (color_tab[j] == 0)
		return -1;
	j++;
	color->g = ft_atoi(tab);
	i = 0;
	while (color_tab[j] && color_tab[j] != ',')
		tab[i++] = color_tab[j++];
	color->b = ft_atoi(tab);
	return (free(tab), 0);
}

int check_good_format_color(t_data *data)
{
	if (!(data->ceiling->r >= 0 && data->ceiling->r <= 255) ||
		!(data->ceiling->g >= 0 && data->ceiling->g <= 255) ||
		!(data->ceiling->b >= 0 && data->ceiling->b <= 255) ||
		!(data->floor->r >= 0 && data->floor->r <= 255) ||
		!(data->floor->g >= 0 && data->floor->g <= 255) ||
		!(data->floor->b >= 0 && data->floor->b <= 255))
		return -1;
	return 0;
} 

int parsing(t_data *data)
{
	int fd;

	if (check_name_map(data->map) == -1)
	{
		
		return (ft_print_error("Wrong file name."), -1);
	}
	fd = open(data->map->map_file, O_RDONLY, 0700);
	if (fd < 0)
	{
		return (perror("Error"), -1);
	}
	if (get_info(data, fd) == 1)
	{
		close(fd);
		return (ft_print_error("One of the parameters is not correctly written"), -1);
	}
		else if (check_map_closed(data->map) == 1)
	{
		close(fd);
		return (ft_print_error("The map is not closed"), -1);
	}
	close(fd);
	if (color_to_int(data->F_color, data->floor,0) == -1)
	{
		return (ft_print_error("The color of the floor doesn't have a rgb format."), -1);
	}
	if (color_to_int(data->C_color, data->ceiling,0) == -1)
	{
		return (ft_print_error("The color of the ceiling doesn't have a rgb format."), -1);
	}
	if (check_good_format_color(data) == -1)
	{
		return (ft_print_error("Each number of the rgb color must be between 0 and 255."), -1);
	}
	printf("colorrrr f : %ld, %ld, %ld\n",data->floor->r, data->floor->g, data->floor->b );
	printf("colorrrr c : %ld, %ld, %ld\n",data->ceiling->r, data->ceiling->g, data->ceiling->b );

	return 0;
}
