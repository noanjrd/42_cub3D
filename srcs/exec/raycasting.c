/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:17:36 by njard             #+#    #+#             */
/*   Updated: 2025/08/27 14:59:49 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

// static void	put_image(t_fractal **fractal)
// {
// 	mlx_put_image_to_window((*fractal)->mlx, (*fractal)->win,
// 		(*fractal)->img, 0, 0);
// 	return ;
// }

void draw_floor_ceiling(t_data *data, t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			if (y < WINDOW_HEIGHT / 2)
				((int *)mlx->addr)[y * WINDOW_WIDTH + x] = data->ceiling->color;
			else
				((int *)mlx->addr)[y * WINDOW_WIDTH + x] = data->floor->color;
			y++;
		}
		x++;
	}
}

void raycasting(t_data *data, t_mlx *mlx, t_game *game, t_player *player)
{
	draw_floor_ceiling(data, mlx);

	int x;

	while(!done())
	{
		int w = WINDOW_WIDTH;
		for(int x = 0; x < w; x++)
		{
			game->cameraX = 2 * x / (double)w - 1; // mettre la camera entre -1 et 1
			game->rayDirX = player->dirX + player->planeX * game->cameraX; // calculer ou va le rayon (milieu de l ecran + fov * x (-1 a 1))
			game->rayDirY = player->dirY + player->planeY * game->cameraX;
		}
		
		int mapX = (int)player->posX;
		int mapY = (int)player->posY;

		// longueur de la position du joueur jusqu a la premiere intercetion
		// il faut rajouter delta a chaque case apres
		double sideDistX;
		double sideDistY;

		// Longueur reel du rayon lorsque on parcour 1 case en x puis y
		if (game->rayDirX == 0)
			game->deltaDistX = abs(1 / game->rayDirX); // version simplifie du calcul de l hypotenuse
		else
			game->deltaDistX = 100000000.0;

		if (game->rayDirY == 0)
			game->deltaDistY = abs(1 / game->rayDirY);
		else
			game->deltaDistY = 100000000.0;

		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		// calcul de la lonhueur du rayon jusqu au premier  mur
		if (game->rayDirX < 0)
		{
			stepX = -1;
			// on part du mur gauche de la case et on ajoute la position du joueur
			sideDistX = (player->posX - mapX) * game->deltaDistX;
		}
		else
		{
			stepX = 1;
			//ici on fait plus 1 pour partir du mur droit puis soustraire la valur x ou est le joueur dans la case
			sideDistX = (mapX - player->posX + 1) * game->deltaDistX;
		}
		if (game->rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (player->posY - mapY) * game->deltaDistY;
		}
		else 
		{
			stepY = 1;
			sideDistY = (mapY - player->posY + 1) * game->deltaDistY;
		}

		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img, 0, 0);
		
	}
	
	mlx_loop(mlx->mlx);
}
