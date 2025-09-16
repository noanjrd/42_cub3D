/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinguet <mpinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:11:00 by mpinguet          #+#    #+#             */
/*   Updated: 2025/09/16 16:11:00 by mpinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	on_key_press(int keycode, t_data *data)
{
	if (keycode == 119)
		data->move_up = 1;
	if (keycode == 115)
		data->move_down = 1;
	if (keycode == 97)
		data->move_left = 1;
	if (keycode == 100)
		data->move_right = 1;
	if (keycode == 65361)
		data->rotate_left = 1;
	if (keycode == 65363)
		data->rotate_right = 1;
	return (0);
}

int	on_key_release(int keycode, t_data *data)
{
	if (keycode == 65307)
		destroy_window(data);
	if (keycode == 119)
		data->move_up = 0;
	if (keycode == 115)
		data->move_down = 0;
	if (keycode == 97)
		data->move_left = 0;
	if (keycode == 100)
		data->move_right = 0;
	if (keycode == 65361)
		data->rotate_left = 0;
	if (keycode == 65363)
		data->rotate_right = 0;
	return (0);
}

void	key_action(t_data *data)
{
	if (data->move_up == 1 && touch_wall(data) != 1)
	{
		data->player->y += 0.06 * data->player->dir_y;
		data->player->x += 0.06 * data->player->dir_x;
	}
	if (data->move_down == 1 && touch_wall(data) != 1)
	{
		data->player->y -= 0.06 * data->player->dir_y;
		data->player->x -= 0.06 * data->player->dir_x;
	}
	if (data->move_left == 1 && touch_wall(data) != 1)
	{
		data->player->y -= 0.06 * data->player->plane_y;
		data->player->x -= 0.06 * data->player->plane_x;
	}
	if (data->move_right == 1 && touch_wall(data) != 1)
	{
		data->player->y += 0.06 * data->player->plane_y;
		data->player->x += 0.06 * data->player->plane_x;
	}
	if (data->rotate_left == 1)
		arrow_left(data);
	if (data->rotate_right == 1)
		arrow_right(data);
}

int	close_window(t_data *data)
{
	destroy_window(data);
	return (0);
}
