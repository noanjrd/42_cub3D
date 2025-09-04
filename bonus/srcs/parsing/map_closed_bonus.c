/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:29:33 by njard             #+#    #+#             */
/*   Updated: 2025/09/04 11:43:14 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	check_each_zero(int i, int j, char c, t_map *map)
{
	if (c == '0' || c == 'S' || c == 'N' || c == 'W' || c == 'O')
	{
		if (map->map[i][j - 1] == 'X' || map->map[i][j + 1] == 'X')
		{
			return (1);
		}
		if (map->map[i - 1][j] == 'X' || map->map[i + 1][j] == 'X')
			return (1);
	}
	return (0);
}

int	check_map_closed(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (check_each_zero(i, j, map->map[i][j], map))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
