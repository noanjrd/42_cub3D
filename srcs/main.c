/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 10:57:45 by njard             #+#    #+#             */
/*   Updated: 2025/07/21 16:19:23 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int main(int argc, char **argv)
{
	t_data *data;

	if (argc == 1)
		return (ft_print_error("Miss an argument"),0);
	if (argc > 2)
		return (ft_print_error("Too many arguments"),0);
	data = malloc(sizeof(t_data));
	ft_init_data(data, argv);
	parsing(data);
	printf("NO : %s\n", data->NO_texture);
	printf("SO : %s\n", data->SO_texture);
	printf("WE : %s\n", data->WE_texture);
	printf("EA : %s\n", data->EA_texture);
	printf("F : %s\n", data->F_color);
	printf("C : %s\n", data->C_color);
	ft_free_data(data);
	return 0;
}
