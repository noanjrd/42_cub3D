/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:58:28 by njard             #+#    #+#             */
/*   Updated: 2025/07/13 13:57:18 by njard            ###   ########.fr       */
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

char	*ft_strjoin(char *buffer, char *temp)
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

char	*update_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (ft_free_buffer(buffer, buffer, 0));
	i++;
	new_buffer = malloc(ft_strlen(buffer) - i + 1);
	if (!new_buffer)
		return (ft_free_buffer(buffer, buffer, 0));
	while (buffer[i] != '\0')
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

int	buffer_contains_newline(char *buffer)
{
	int	i;

	i = 0;
	if (! buffer)
		return (0);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_buffer(int fd, char *buffer)
{
	int		end;
	char	*temp;
	int		bytes_read;

	temp = malloc(sizeof(char) * (1000 + 1));
	if (! temp)
		return (ft_free_buffer(buffer, temp, 1));
	end = buffer_contains_newline(buffer);
	while (! end)
	{
		bytes_read = read(fd, temp, 1000);
		if (bytes_read < 0)
			return (ft_free_buffer(buffer, temp, 1));
		if (bytes_read == 0)
			break ;
		temp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp);
		if (! buffer)
			return (NULL);
		end = buffer_contains_newline(buffer);
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || 1000 <= 0)
		return (NULL);
	buffer = get_buffer(fd, buffer);
	if (! buffer || buffer[0] == '\0')
		return (ft_free_buffer(buffer, buffer, 1));
	line = get_line_from_buffer(buffer);
	buffer = update_buffer(buffer);
	return (line);
}
