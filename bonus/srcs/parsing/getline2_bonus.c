/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:58:28 by njard             #+#    #+#             */
/*   Updated: 2025/07/16 15:01:14 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

char	*ft_free_buffer(char *buffer, char *chaine, int put_NULL)
{
	if (chaine != buffer)
		free(chaine);
	if (buffer)
		free(buffer);
	if (put_NULL == 1)
		buffer = NULL;
	return (NULL);
}

char	*ft_strjoin_gnl(char *buffer, char *temp)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	new = malloc(ft_strlen(buffer) + ft_strlen(temp) + 1);
	if (!new)
		return (ft_free_buffer(buffer, buffer, 0));
	if (buffer)
	{
		j = 0;
		while (buffer[j])
			new[i++] = buffer[j++];
	}
	if (temp)
	{
		j = 0;
		while (temp[j])
			new[i++] = temp[j++];
	}
	new[i] = '\0';
	if (buffer)
		free(buffer);
	return (new);
}

char	*get_line_from_buffer(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}
