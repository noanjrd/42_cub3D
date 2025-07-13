/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:25:42 by njard             #+#    #+#             */
/*   Updated: 2025/07/13 15:19:39 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_init_data(t_data *data, char **argv)
{
	data->map_file = argv[1];
	data->NO_texture = NULL;
	data->WE_texture = NULL;
	data->EA_texture = NULL;
	data->SO_texture = NULL;
	data->F_color = NULL;
	data->C_color = NULL;
	data->map = NULL;
	data->map_height = 0;
	return ;
}
