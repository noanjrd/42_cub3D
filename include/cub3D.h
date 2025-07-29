/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:00:21 by njard             #+#    #+#             */
/*   Updated: 2025/07/29 14:13:58 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define WINDOW_WIDTH 100
#define WINDOW_HEIGHT 100

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

typedef struct t_data
{
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
} t_data;


// PARSING

char	*get_line_from_buffer(char *buffer);
char	*ft_free_buffer(char *buffer, char *chaine, int put_NULL);
char	*ft_strjoin_gnl(char *buffer, char *temp);
int parsing(t_data *data);
char	*get_next_line(int fd);
void	get_map(t_map *map, int fd);
int skip_old_line(char *line);
int ft_check_map_error(t_map *map, int fd);
int check_map_closed(t_map *map);
int get_info(t_data *data, int fd);
char *ft_copy_info(char *line);
int check_first_param(t_data *data);
int check_good_format_color(t_data *data);
int	color_to_int(char *color_tab, t_color *color, int j);
int check_string_beggining(char *s1, char *s2, int texture);
int copy_line_map(t_map *map, char *line, int z, int i);

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