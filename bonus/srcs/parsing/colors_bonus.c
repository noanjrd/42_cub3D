/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:39:03 by njard             #+#    #+#             */
/*   Updated: 2025/09/09 18:47:51 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	parse_component(char *color_tab, int *j, long *out)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(150);
	if (!tab)
		return (-1);
	while (color_tab[*j] && color_tab[*j] != ',')
		tab[i++] = color_tab[(*j)++];
	tab[i] = '\0';
	if (i < 1 || ft_atoi(tab) == -1)
		return (free(tab), -1);
	*out = ft_atoi(tab);
	free(tab);
	if (color_tab[*j] == ',')
		(*j)++;
	return (0);
}

int	color_to_int(char *color_tab, t_color *color, int j, int i)
{
	(void)i;
	if (parse_component(color_tab, &j, &color->r) == -1)
		return (-1);
	if (parse_component(color_tab, &j, &color->g) == -1)
		return (-1);
	if (parse_component(color_tab, &j, &color->b) == -1)
		return (-1);
	return (0);
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
