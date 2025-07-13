/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:00:21 by njard             #+#    #+#             */
/*   Updated: 2025/07/13 15:00:01 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct t_data
{
	char *map_file;
	char *NO_texture;
	char *SO_texture;
	char *WE_texture;
	char *EA_texture;
	char *F_color;
	char *C_color;
	char **map;
	int map_height;
} t_data;



// PARSING

void parsing(t_data *data);
char	*get_next_line(int fd);
int	get_map(t_data *data, int fd);

// UTILS

int	ft_strlen(char *chaine);
int check_string_beggining(char *s1, char *s2);
void ft_free(t_data *data);
int ft_print_error(char *s);
void	ft_init_data(t_data *data, char **argv);
void ft_print_tab(char **tab);