/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinguet <mpinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:00:21 by njard             #+#    #+#             */
/*   Updated: 2025/08/19 17:17:03 by mpinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

#define WRONG_COLOR_FORMAT "The color of the floor doesn't have a rgb format."
#define NOT_RGB "The color of the ceiling doesn't have a rgb format."
#define NOT_A_BYTE "Each number of the rgb color must be between 0 and 255."
#define WINDOW_WIDTH 1500
#define WINDOW_HEIGHT 900

typedef struct t_color
{
	long r;
	long	g;
	long	b;
}	t_color;


typedef struct t_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		number;
	int		bits_per_pixel;
	int		line_length;
	int		line_height;
	int		endian;
} t_mlx;

typedef struct t_map
{
	char *map_file;
	char **map;
	int map_height;
	int map_length;
	int nb_player;
	char *l;
} t_map;

typedef struct t_texture
{
	double tex_pos;
	int tex_x;
	int tex_y;
	int col_ceil;
	int col_floor;
	int color;
	void *wall_N;
	void *wall_S;
	void *wall_E;
	void *wall_W;
	void *floor;
	void *ceiling;
} t_texture;
typedef struct t_player
{
	double x; //position x sur la carte (col)
	double y; // position y sur la carte (ligne)
	double dir_x; // vecteur direction x
	double dir_y; //vecteur direction y
	double plane_x; //plan camera x
	double plane_y; //plan camera y
	double ray_dir_y;
	double ray_dir_x;
	double camera_x;
	double delta_x;
    double delta_y;
	int hit;
	int map_x;
	int map_y;
	int side;
	char spawn;
	double perp_wall_dist;
} t_player;

typedef struct t_data
{
	void *wall_texture;
	char *NO_texture;
	char *SO_texture;
	char *WE_texture;
	char *EA_texture;
	char *F_color;
	char *C_color;
	t_map *map;
	t_color *ceiling;
	t_color *floor;
	t_mlx *mlx;
	t_player *player;
	t_texture *texture;
} t_data;


// PARSING

char	*get_line_from_buffer(char *buffer);
char	*ft_free_buffer(char *buffer, char *chaine, int put_NULL);
char	*ft_strjoin_gnl(char *buffer, char *temp);
int parsing(t_data *data);
char	*get_next_line(int fd);
int	get_map(t_map *map, int fd);
int skip_old_line(char *line);
int ft_check_map_error(t_map *map, int fd);
int check_map_closed(t_map *map);
int get_info(t_data *data, int fd);
char *ft_copy_info(char *line);
int check_first_param(t_data *data);
int check_good_format_color(t_data *data);
int	color_to_int(char *color_tab, t_color *color);
int check_string_beggining(char *s1, char *s2, int texture);
int copy_line_map(t_map *map, char *line, int z, int i);
void fill_line(t_map *map, int z, int start, int end);

// UTILS

int	ft_strlen(char *chaine);
int check_string_beggining(char *s1, char *s2, int texture);
void ft_free_data(t_data *data);
void ft_print_error(char *s);
void	ft_init_data(t_data *data, char **argv);
void ft_print_tab(char **tab);
int ft_strcmp_space(char *s1, char *s2);
long	ft_atoi(const char *nptr);

// EXECUTION

void init_mlx(t_data *data);
int close_window(t_data *data);
int manage_window(int keycode, t_data *data);
int calcul_display(t_data *data);
void init_position(t_data *data);
void init_player(t_data *data);
void init_dir(t_data *data);
void 	init_plane(t_data *data);
double cast_ray (t_data *data, double ray_dir_x, double ray_dir_y);
void draw_column(t_data *data,int x, int draw_start, int draw_end);
int key_action(int keycode, t_data *data);
void calcul_player(t_data *data);
void clear_image(t_data *data);
void destroy_window(t_data *data);
void free_map(t_map *map);
void init_texture(t_data *data);
char    **ft_split(char const *s, char c);
void free_split(char **tab);
void init_draw_start_end(int *draw_start, int *draw_end, int *wall_height,
    double *step);
void init_wall_x(double *wall_x, t_data *data);
void wall_ver_or_hor(t_data *data);
int get_texture_pixel(t_data *data, void *texture_img, int tex_x, int tex_y);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
void color_ceil_floor(t_data *data, int n);
