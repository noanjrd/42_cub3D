/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:17:36 by njard             #+#    #+#             */
/*   Updated: 2025/09/01 12:18:25 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void raycasting(t_data *data, t_mlx *mlx, t_game *game, t_player *player)
{
	int x = 0;

	int check = 0;
	int color;
	while (x < WINDOW_WIDTH)
	{
		game->cameraX = 2 * x / (double)WINDOW_WIDTH - 1; // mettre la camera entre -1 et 1
		game->rayDirX = player->dirX + (player->planeX * game->cameraX); // calculer ou va le rayon (milieu de l ecran + fov * x (de -1 a 1))
		game->rayDirY = player->dirY + (player->planeY * game->cameraX);

		int mapX;
		mapX = (int)player->posX; // on arrondi en coupant la parti decimal (donc on arrondi en dessous sans tous les cas)
		int mapY;
		mapY = (int)player->posY;

		// longueur de la position du joueur jusqu a la premiere intercetion,	il faut rajouter delta a chaque case apres
		double sideDistX;
		sideDistX  = 0;
		double sideDistY;
		sideDistY = 0;

		// Longueur reel du rayon lorsque on parcour 1 case en x puis y
		if (game->rayDirX != 0)
			game->deltaDistX = fabs(1 / game->rayDirX); 
		else
			game->deltaDistX = 100000000.0;
		if (game->rayDirY != 0)
			game->deltaDistY = fabs(1 / game->rayDirY);
		else
			game->deltaDistY = 100000000.0;

		double perpWallDist;

		// quel est lq direction de x et y (y etant toujours inverse)
		int stepX;
		int stepY;

		int hit;
		hit = 0; //se met a 1 si un mur est touche
		int side; // quelles face a ete touche, soit side == 0 c est WE ou l autre SN

		// calcul de la longueur du rayon jusqu au premier  mur
		if (game->rayDirX < 0) // le rayon part vers la gauche 
		{
			stepX = -1;
			// ici on calcul la distance et le mur gauche, entre parenthese c est las distance entre le joueur et le mur gauche
			sideDistX = (player->posX - mapX) * game->deltaDistX;
		}
		else
		{
			stepX = 1;
			// ici pareil mais avec le mur droit 
			sideDistX = (mapX - player->posX + 1) * game->deltaDistX;
		}
		if (game->rayDirY < 0) // comme les y sont inverse ca veut dire que c est en haut de l ecran
		{
			stepY = -1;
			sideDistY = (player->posY - mapY) * game->deltaDistY;
		}
		else // en bas de l ecran
		{
			stepY = 1;
			sideDistY = (mapY - player->posY + 1) * game->deltaDistY;
		}
		while (hit == 0)
		{
			// on ajoute la distance x ou y et on incremente la map pour savoir si on touche un mur
			// donc a chque iteration ca change de if
			//sideDistY est encore inversé
			if (sideDistX < sideDistY)
			{
				sideDistX += game->deltaDistX;
				mapX+= stepX;
				side = 0;
			}
			else // ici si ont veut monter dans la map on fait donc -1 car map[0] est le haut gaiuche de la map
			{
				sideDistY += game->deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (data->map->map[mapY][mapX] == '1')
				hit = 1;
		}
		if (side == 0) // si le mur est un WE on supprime 1 distance en trop
			perpWallDist = (sideDistX - game->deltaDistX);
		else
			perpWallDist = (sideDistY - game->deltaDistY);


		int h;
		h = WINDOW_HEIGHT;
			
		int lineHeight;
		lineHeight = (int)(h / perpWallDist);

		int drawStart;
		int drawEnd;
		drawStart= -lineHeight / 2 + h / 2;
		if(drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h)
			drawEnd = h - 1;

		for (int y = 0; y <= drawStart; y++)
			my_mlx_pixel_put(mlx, x, y, data->ceiling->color);
		for (int y = drawEnd; y < WINDOW_HEIGHT ; y++)
			my_mlx_pixel_put(mlx, x, y, data->floor->color);


		double wallX; // position exacte du hit sur le mur
		if (side == 0) // mur west ou east donc on a avance x pour le touche
			wallX = player->posY + perpWallDist * game->rayDirY; // calcul du cordonne Y de l impact : position du joueur + (distance du rayon × direction du rayon)
		else
			wallX = player->posX + perpWallDist * game->rayDirX;
		wallX -= floor(wallX); //garde la parti fractionnaire pour savoir entre 0 et 1 ou le mur a ete frappe

		// coordonnée X dans la texture
		int texX = (int)(wallX * (double)data->NO->width); // on convertiu la texture en la bonne unite
		if (side == 1 && game->rayDirY > 0) // on remet la texture dans le bon sens pour sud
			texX = data->NO->width - texX - 1;

		double step = 1.0 * data->NO->height / lineHeight; // hauteur de la bande a dessine
		double texPos = (drawStart - h / 2 + lineHeight / 2) * step; // 

		for (int y = drawStart; y <= drawEnd; y++)
		{
			int texY = (int)texPos % (data->NO->height - 1); // modulo hauteur texture
			texPos += step;
			char *pixel;
			if (side == 0 && stepX == -1)
				pixel = data->WE->addr + (texY * data->WE->line_length + texX * (data->WE->bits_per_pixel / 8));
			if (side == 0 && stepX == 1)
				pixel = data->EA->addr + (texY * data->EA->line_length + texX * (data->EA->bits_per_pixel / 8));
			if (side == 1 && stepY == -1)
				pixel = data->NO->addr + (texY * data->NO->line_length + texX * (data->NO->bits_per_pixel / 8));
			if (side == 1 && stepY == 1)
				pixel = data->SO->addr + (texY * data->SO->line_length + texX * (data->SO->bits_per_pixel / 8));
			int texColor = *(unsigned int*)pixel;

			if (side == 1) // assombrir les murs Nord/Sud
				texColor = (texColor >> 1) & 0x7F7F7F; // ou 0x7F7F7F (aka 8355711)

			my_mlx_pixel_put(mlx, x, y, texColor);
		}
		x++;

	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
