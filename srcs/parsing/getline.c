/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 11:58:28 by njard             #+#    #+#             */
/*   Updated: 2025/07/16 15:01:51 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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
		buffer = ft_strjoin_gnl(buffer, temp);
		if (! buffer)
			return (NULL);
		end = buffer_contains_newline(buffer);
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[80];
	char		*line;

	if (fd < 0 || fd >= 80)
		return (NULL);
	buffer[fd] = get_buffer(fd, buffer[fd]);
	if (! buffer[fd] || buffer[fd][0] == '\0')
		return (ft_free_buffer(buffer[fd], buffer[fd], 1));
	line = get_line_from_buffer(buffer[fd]);
	buffer[fd] = update_buffer(buffer[fd]);
	return (line);
}
