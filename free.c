/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:17:35 by njard             #+#    #+#             */
/*   Updated: 2025/07/13 13:22:30 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3D.h"

void ft_free(t_data *data)
{
	free(data->C_color);
	free(data->F_color);
	free(data->NO_texture);
	free(data->SO_texture);
	free(data->WE_texture);
	free(data->EA_texture);
	free(data);
}
