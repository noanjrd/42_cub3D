/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:05:58 by njard             #+#    #+#             */
/*   Updated: 2025/09/08 17:01:45 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	mouse_move(int x, int y, t_data *data)
{
	double	degree;

	(void)y;
	degree = 0.03;
	if (x <= WINDOW_WIDTH / 3)
	{
		change_direction(data, -degree);
	}
	if (x >= (WINDOW_WIDTH / 3) * 2)
	{
		change_direction(data, degree);
	}
	return (0);
}

int	check_wall(char **map, int y, int x)
{
	if (map[y][x] != '1')
	{
		return (0);
	}
	if (map[y + 1][x] && map[y + 1][x] == 'X')
		return (1);
	if (map[y - 1][x] && map[y - 1][x] == 'X')
		return (1);
	if (map[y][x + 1] && map[y][x + 1] == 'X')
		return (1);
	if (map[y][x - 1] && map[y][x - 1] == 'X')
		return (1);
	return (0);
}

int	on_key_press(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		data->quit = 1;
	if (keycode == W)
		data->move_up = 1;
	if (keycode == S)
		data->move_down = 1;
	if (keycode == A)
		data->move_left = 1;
	if (keycode == D)
		data->move_right = 1;
	if (keycode == ROTATE_L)
		data->rotate_left = 1;
	if (keycode == ROTATE_R)
		data->rotate_right = 1;
	return (0);
}

int	on_key_release(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		data->quit = 0;
	if (keycode == W)
		data->move_up = 0;
	if (keycode == S)
		data->move_down = 0;
	if (keycode == A)
		data->move_left = 0;
	if (keycode == D)
		data->move_right = 0;
	if (keycode == ROTATE_L)
		data->rotate_left = 0;
	if (keycode == ROTATE_R)
		data->rotate_right = 0;
	return (0);
}

void	handle_player_actions(t_data *data)
{
	if (data->move_up)
		move_player_forward(data);
	if (data->move_down)
		move_player_backward(data);
	if (data->move_left)
		move_player_left(data);
	if (data->move_right)
		move_player_right(data);
	if (data->rotate_left)
		change_direction(data, -0.0066);
	if (data->rotate_right)
		change_direction(data, 0.0066);
	if (data->quit)
		ft_destroy_window(data);
}
