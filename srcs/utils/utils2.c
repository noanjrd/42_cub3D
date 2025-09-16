/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinguet <mpinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:57:31 by njard             #+#    #+#             */
/*   Updated: 2025/09/16 17:43:52 by mpinguet         ###   ########.fr       */
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

int	texture_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

void	calcul_draw_start_end(double *wall_dist, t_data *data, int *draw_start,
		int *draw_end)
{
	data->mlx->line_height = (int)(WINDOW_HEIGHT / *wall_dist);
	*draw_start = -(data->mlx->line_height) / 2 + WINDOW_HEIGHT / 2;
	*draw_end = data->mlx->line_height / 2 + WINDOW_HEIGHT / 2;
}

void	calcul_x_y_wall(t_data *data, int *x, int *y)
{
	if (data->move_up == 1)
	{
		*y = floor(data->player->y + (0.2 * data->player->dir_y));
		*x = floor(data->player->x + (0.2 * data->player->dir_x));
	}
	else if (data->move_down == 1)
	{
		*y = floor(data->player->y - (0.2 * data->player->dir_y));
		*x = floor(data->player->x - (0.2 * data->player->dir_x));
	}
	else if (data->move_left == 1)
	{
		*y = floor(data->player->y - (0.2 * data->player->plane_y));
		*x = floor(data->player->x - (0.2 * data->player->plane_x));
	}
	else if (data->move_right == 1)
	{
		*y = floor(data->player->y + (0.2 * data->player->plane_y));
		*x = floor(data->player->x + (0.2 * data->player->plane_x));
	}
}

void	calcul_cast_ray(t_data *data)
{
	data->player->map_x = (int)data->player->x;
	data->player->map_y = (int)data->player->y;
	data->player->hit = 0;
	init_delta(data);
}
