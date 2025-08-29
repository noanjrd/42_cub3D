/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 10:57:45 by njard             #+#    #+#             */
/*   Updated: 2025/08/29 11:39:59 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

// enlever le relink

int main(int argc, char **argv)
{
	t_data *data;

	if (argc == 1)
		return (ft_print_error("Miss an argument"),0);
	if (argc > 2)
		return (ft_print_error("Too many arguments"),0);
	data = malloc(sizeof(t_data));
	ft_init_data(data, argv);
	if (parsing(data) == 0)
	{
		printf("NO : %s\n", data->NO_texture);
		printf("SO : %s\n", data->SO_texture);
		printf("WE : %s\n", data->WE_texture);
		printf("EA : %s\n", data->EA_texture);
		printf("F : %s\n", data->F_color);
		printf("C : %s\n", data->C_color);
		printf("colorrrr f : %ld, %ld, %ld\n",data->floor->r, data->floor->g, data->floor->b);
		printf("colorrrr c : %ld, %ld, %ld\n",data->ceiling->r, data->ceiling->g, data->ceiling->b);
		ft_init_player(data->player, data->map->map);
		init_mlx(data);
	}
	
	ft_free_data(data);
	return 0;
}
