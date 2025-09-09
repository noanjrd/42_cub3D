/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:17:36 by njard             #+#    #+#             */
/*   Updated: 2025/09/08 17:00:19 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_texture(t_data *data, t_mlx *mlx, t_game *game, int x)
{
	game->y = game->drawstart;
	while (game->y <= game->drawend)
	{
		game->texy = (int)(game->texpos);
		game->texpos += game->step;
		if (game->side == 0 && game->stepx == -1)
			game->pixel = data->we->addr + (game->texy * data->we->line_length
					+ game->texx * (data->we->bits_per_pixel / 8));
		if (game->side == 0 && game->stepx == 1)
			game->pixel = data->ea->addr + (game->texy * data->ea->line_length
					+ game->texx * (data->ea->bits_per_pixel / 8));
		if (game->side == 1 && game->stepy == -1)
			game->pixel = data->no->addr + (game->texy * data->no->line_length
					+ game->texx * (data->no->bits_per_pixel / 8));
		if (game->side == 1 && game->stepy == 1)
			game->pixel = data->so->addr + (game->texy * data->so->line_length
					+ game->texx * (data->so->bits_per_pixel / 8));
		game->texcolor = *(unsigned int *)game->pixel;
		my_mlx_pixel_put(mlx, x, game->y, game->texcolor);
		game->y++;
	}
}

int	raycasting(t_data *data)
{
	int	x;

	x = 0;
	handle_player_actions(data);
	while (x < WINDOW_WIDTH)
	{
		calcul_delta(data->game, data->player, x);
		calcul_sidedist(data->game, data->player);
		calcul_hit(data, data->game);
		calcul_draw_end_start(data, data->mlx, data->game, x);
		calcul_texture(data, data->game, data->player);
		draw_texture(data, data->mlx, data->game, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->img, 0,
		0);
	return (0);
}
