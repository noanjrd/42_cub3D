/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:39:03 by njard             #+#    #+#             */
/*   Updated: 2025/09/06 14:44:36 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	color_to_int(char *color_tab, t_color *color, int j, int i)
{
	char	*tab;

	tab = malloc(150);
	while (color_tab[j] && color_tab[j] != ',')
		tab[i++] = color_tab[j++];
	if (color_tab[j] == 0 || i > 3)
		return (free(tab), -1);
	j++;
	tab[i] = 0;
	color->r = ft_atoi(tab);
	i = 0;
	while (color_tab[j] && color_tab[j] != ',')
		tab[i++] = color_tab[j++];
	if (color_tab[j] == 0 || i > 3)
		return (free(tab), -1);
	j++;
	color->g = ft_atoi(tab);
	i = 0;
	while (color_tab[j] && color_tab[j] != ',')
		tab[i++] = color_tab[j++];
	if (i > 3)
		return (free(tab), -1);
	color->b = ft_atoi(tab);
	return (free(tab), 0);
}

int	check_good_format_color(t_data *data)
{
	if (!(data->ceiling->r >= 0 && data->ceiling->r <= 255)
		|| !(data->ceiling->g >= 0 && data->ceiling->g <= 255)
		|| !(data->ceiling->b >= 0 && data->ceiling->b <= 255)
		|| !(data->floor->r >= 0 && data->floor->r <= 255)
		|| !(data->floor->g >= 0 && data->floor->g <= 255)
		|| !(data->floor->b >= 0 && data->floor->b <= 255))
		return (-1);
	data->ceiling->color = (data->ceiling->r << 16)
		| (data->ceiling->g << 8) | data->ceiling->b;
	data->floor->color = (data->floor->r << 16)
		| (data->floor->g << 8) | data->floor->b;
	return (0);
}
