/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calculations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:17:36 by njard             #+#    #+#             */
/*   Updated: 2025/09/04 13:47:59 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	calcul_delta(t_game *game, t_player *player, int x)
{
	double	camerax;

	camerax = 2 * x / (double)WINDOW_WIDTH - 1;
	game->raydirx = player->dirx + (player->planex * camerax);
	game->raydiry = player->diry + (player->planey * camerax);
	game->mapx = (int)player->posx;
	game->mapy = (int)player->posy;
	game->sidedistx = 0;
	game->sidedisty = 0;
	if (game->raydirx != 0)
		game->deltadistx = fabs(1 / game->raydirx);
	else
		game->deltadistx = 100000000.0;
	if (game->raydiry != 0)
		game->deltadisty = fabs(1 / game->raydiry);
	else
		game->deltadisty = 100000000.0;
}

void	calcul_sidedist(t_game *game, t_player *player)
{
	if (game->raydirx < 0)
	{
		game->stepx = -1;
		game->sidedistx = (player->posx - game->mapx) * game->deltadistx;
	}
	else
	{
		game->stepx = 1;
		game->sidedistx = (game->mapx - player->posx + 1) * game->deltadistx;
	}
	if (game->raydiry < 0)
	{
		game->stepy = -1;
		game->sidedisty = (player->posy - game->mapy) * game->deltadisty;
	}
	else
	{
		game->stepy = 1;
		game->sidedisty = (game->mapy - player->posy + 1) * game->deltadisty;
	}
}

void	calcul_hit(t_data *data, t_game *game)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (game->sidedistx < game->sidedisty)
		{
			game->sidedistx += game->deltadistx;
			game->mapx += game->stepx;
			game->side = 0;
		}
		else
		{
			game->sidedisty += game->deltadisty;
			game->mapy += game->stepy;
			game->side = 1;
		}
		if (data->map->map[game->mapy][game->mapx] == '1')
			hit = 1;
	}
	if (game->side == 0)
		game->perpwalldist = (game->sidedistx - game->deltadistx);
	else
		game->perpwalldist = (game->sidedisty - game->deltadisty);
}

void	calcul_draw_end_start(t_data *data, t_mlx *mlx, t_game *game, int x)
{
	int	h;
	int	y;

	y = 0;
	h = WINDOW_HEIGHT;
	game->lineheight = (int)(h / game->perpwalldist);
	game->drawstart = (-game->lineheight / 2) + h / 2;
	game->drawend = (game->lineheight / 2) + h / 2;
	if (game->drawstart < 0)
		game->drawstart = 0;
	if (game->drawend >= h)
		game->drawend = h - 1;
	while (y <= game->drawstart)
	{
		my_mlx_pixel_put(mlx, x, y, data->ceiling->color);
		y++;
	}
	y = game->drawend;
	while (y <= h)
	{
		my_mlx_pixel_put(mlx, x, y, data->floor->color);
		y++;
	}
}

void	calcul_texture(t_data *data, t_game *game, t_player *player)
{
	double	wallx;

	if (game->side == 0)
		wallx = player->posy + (game->perpwalldist * game->raydiry);
	else
		wallx = player->posx + (game->perpwalldist * game->raydirx);
	wallx -= floor(wallx);
	game->texx = (int)(wallx * (double)data->no->width);
	if (game->side == 1 && game->raydiry > 0)
		game->texx = data->no->width - (game->texx) - 1;
	game->step = (double)data->no->height / (double)game->lineheight;
	game->texpos = (game->drawstart - (WINDOW_HEIGHT / 2) + (game->lineheight
				/ 2)) * game->step;
}
