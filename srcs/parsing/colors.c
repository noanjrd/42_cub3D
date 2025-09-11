/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:39:03 by njard             #+#    #+#             */
/*   Updated: 2025/07/28 12:01:38 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int nb_comma(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(str[i])
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	return (j);
}

int	color_to_int(char *color_tab, t_color *color)
{
	char	**split;

	if (nb_comma(color_tab) != 2)
		return (-1);
	split = ft_split(color_tab, ',');
	// printf("split = %s\n", split[0]);
	if (!split || !split[0] || !split[1] || !split[2])
		return (-1);
	color->r = ft_atoi(split[0]);
	color->g = ft_atoi(split[1]);
	color->b = ft_atoi(split[2]);
	if (color->r < 0 || color->g < 0 || color->b < 0 )
		return (-1);
	free_split(split);
	return (0);
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

