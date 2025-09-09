/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:00:21 by njard             #+#    #+#             */
/*   Updated: 2025/09/09 22:52:40 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define PARAM_WRITTEN "One of the parameters is not correctly written."
#define WRONG_COLOR_FORMAT "The color of the floor doesn't have a rgb format."
#define NOT_RGB "The color of the ceiling doesn't have a rgb format."
#define NOT_A_BYTE "Each number of the rgb color must be between 0 and 255."
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define RIGHT 1
#define LEFT 0
#define ESCAPE 65307
#define ESCAPE 65307
#define W 119
#define A 97
#define S 115
#define D 100
#define ROTATE_L 65361
#define ROTATE_R 65363

typedef struct t_color
{
	long		r;
	long		g;
	long		b;
	long		color;
}				t_color;

typedef struct t_texture
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_texture;

typedef struct t_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			number;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx;

typedef struct t_map
{
	char		*map_file;
	char		**map;
	int			map_height;
	int			map_length;
	int			nb_player;
	char		*l;
}				t_map;

typedef struct s_player
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
}				t_player;

typedef struct t_game
{
	double		oldtime;
	double		raydirx;
	double		raydiry;
	double		texpos;
	double		deltadistx;
	double		deltadisty;
	double		sidedistx;
	double		sidedisty;
	double		perpwalldist;
	double		step;
	int			texx;
	int			mapx;
	int			mapy;
	int			texcolor;
	int			stepx;
	int			stepy;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			texy;
	char		*pixel;
	int			y;

}				t_game;

typedef struct t_data
{
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*f_color;
	char		*c_color;
	bool		move_up;
	bool		move_down;
	bool		move_left;
	bool		move_right;
	bool		rotate_left;
	bool		rotate_right;
	bool		quit;
	t_texture	*no;
	t_texture	*so;
	t_texture	*we;
	t_texture	*ea;
	t_map		*map;
	t_color		*ceiling;
	t_color		*floor;
	t_mlx		*mlx;
	t_player	*player;
	t_game		*game;
}				t_data;

// PARSING

char			*get_line_from_buffer(char *buffer);
char			*ft_free_buffer(char *buffer, char *chaine, int put_NULL);
char			*ft_strjoin_gnl(char *buffer, char *temp);
int				parsing(t_data *data);
char			*get_next_line(int fd);
int				get_map(t_map *map, int fd);
int				skip_old_line(char *line);
int				ft_check_map_error(t_map *map, int fd);
int				check_map_closed(t_map *map);
int				get_info(t_data *data, int fd);
char			*ft_copy_info(char *line);
int				check_first_param(t_data *data);
int				check_good_format_color(t_data *data);
int				color_to_int(char *color_tab, t_color *color, int j, int i);
int				check_string_beggining(char *s1, char *s2, int texture);
int				copy_line_map(t_map *map, char *line, int z, int i);
void			fill_line(t_map *map, int z, int start, int end);

// UTILS

int				ft_strlen(char *chaine);
int				check_string_beggining(char *s1, char *s2, int texture);
void			ft_free_data(t_data *data);
void			ft_print_error(char *s);
void			ft_init_data(t_data *data, char **argv);
void			ft_print_tab(char **tab);
int				ft_strcmp_space(char *s1, char *s2);
long			ft_atoi(const char *nptr);
void			ft_init_map(t_map *map, char **argv);
void			ft_init_game(t_game *game);
void			ft_init_mlx(t_mlx *mlx);
void			ft_free_texture(t_mlx *mlx, t_texture *tex);

// EXECUTION

void			ft_init_player(t_player *player, char **map);
void			init_mlx(t_data *data);
int				raycasting(t_data *data);
int				ft_destroy_window(t_data *data);
int				key_action(int key, t_data *data);
int				check_wall(char **map, int y, int x);
int				mouse_move(int x, int y, t_data *data);
int				mouse_hook(int button, int x, int y, void *param);
void			change_direction(t_data *data, double degree);
void			calcul_delta(t_game *game, t_player *player, int x);
void			calcul_sidedist(t_game *game, t_player *player);
void			calcul_hit(t_data *data, t_game *game);
void			calcul_draw_end_start(t_data *data, t_mlx *mlx, t_game *game,
					int x);
void			calcul_texture(t_data *data, t_game *game, t_player *player);
void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void			handle_player_actions(t_data *data);
int				on_key_press(int keycode, t_data *data);
int				on_key_release(int keycode, t_data *data);
void			handle_player_actions(t_data *data);
void			move_player_forward(t_data *data);
void			move_player_backward(t_data *data);
void			move_player_left(t_data *data);
void			move_player_right(t_data *data);
void			change_direction(t_data *data, double degree);
void			change_direction(t_data *data, double degree);