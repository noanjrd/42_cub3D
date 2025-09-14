/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinguet <mpinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:57:31 by njard             #+#    #+#             */
/*   Updated: 2025/09/14 19:01:48 by mpinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

long	ft_atoi(const char *nptr)
{
	long	i;
	long	nb;
	long	signe;

	i = 0;
	nb = 0;
	signe = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i] != '\0')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	if (nb < 0 || nb > 255)
		return (-1);
	if (nptr[i] == '\0' || nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		return (nb * signe);
	return (-1);
}

int texture_valid(char *str)
{
	int i;

	i = 0;
	while(str[i] && str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}
