/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinguet <mpinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 10:57:42 by njard             #+#    #+#             */
/*   Updated: 2025/09/16 18:04:02 by mpinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 1)
		return (ft_print_error("Miss an argument"), 0);
	if (argc > 2)
		return (ft_print_error("Too many arguments"), 0);
	data = malloc(sizeof(t_data));
	ft_init_data(data, argv);
	if (parsing(data) == 0)
	{
		ft_init_player(data->player, data->map->map);
		init_mlx(data);
	}
	ft_free_data(data);
	return (0);
}
