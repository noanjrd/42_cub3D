/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:30:29 by njard             #+#    #+#             */
/*   Updated: 2025/07/13 15:42:12 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void ft_print_tab(char **tab)
{
	int i;

	i = 0;
	printf("\ntab : ");
	while(tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return ;
}

int ft_print_error(char *s)
{
	int i;

	i = 0;
	write(2, "Error\n", 6);
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	write(2, "\n", 1);
	return 0;
}

int check_string_beggining(char *s1, char *s2)
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
	return (1);
}

