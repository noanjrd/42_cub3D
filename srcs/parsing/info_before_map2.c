/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_before_map2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinguet <mpinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:09:34 by njard             #+#    #+#             */
/*   Updated: 2025/09/16 17:24:45 by mpinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	check_string_beggining_next(char *s1, int texture)
{
	int	i;
	int	j;

	i = 2;
	while (s1[i] == ' ' || (s1[i] >= 7 && s1[i] <= 13))
		i++;
	i++;
	while (s1[i] && s1[i] != ' ' && !(s1[i] >= 7 && s1[i] <= 13))
		i++;
	j = i;
	if (texture == 1 && (s1[j - 1] != 'm' || s1[j - 2] != 'p' || s1[j
				- 3] != 'x'))
		return (0);
	i++;
	while (s1[i])
	{
		if (texture == 1 && (s1[i] == ' ' || (s1[i] >= 7 && s1[i] <= 13)))
			return (0);
		i++;
	}
	return (1);
}

int	check_string_beggining(char *s1, char *s2, int texture)
{
	int	i;

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
	if (!s1[i] || (s1[i] != ' ' && !(s1[i] >= 7 && s1[i] <= 13)))
		return (0);
	while (s1[i] && (s1[i] == ' ' || (s1[i] >= 7 && s1[i] <= 13)))
		i++;
	if (s1[i] == 0)
		return (0);
	return (check_string_beggining_next(s1, texture));
}
