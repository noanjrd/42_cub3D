/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinguet <mpinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:30:29 by njard             #+#    #+#             */
/*   Updated: 2025/09/16 17:44:43 by mpinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	printf("\ntab : \n");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return ;
}

void	ft_print_error(char *s)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	write(2, "\n", 1);
	return ;
}

int	ft_strcmp_space(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	if (ft_strlen(s1) < ft_strlen(s2))
	{
		return (0);
	}
	while (s1[i] && s1[i] != '\n' && (s1[i] == ' ' || (s1[i] >= 7
				&& s1[i] <= 13)))
		i++;
	while (s1[i] && s2[j])
	{
		if (s1[i] != s2[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	ray_touch_wall(t_data *data)
{
	if (data->player->map_x < 0 || data->player->map_x >= data->map->map_length
		|| data->player->map_y < 0
		|| data->player->map_y >= data->map->map_height)
	{
		data->player->hit = 1;
		return (1);
	}
	return (0);
}
