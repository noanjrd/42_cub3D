/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:17:35 by njard             #+#    #+#             */
/*   Updated: 2025/07/13 15:44:16 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void ft_free(t_data *data)
{
	int i;
	free(data->C_color);
	free(data->F_color);
	free(data->NO_texture);
	free(data->SO_texture);
	free(data->WE_texture);
	free(data->EA_texture);
	if (data->map)
	{
		i = 0;
		while(data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	free(data);
}
