/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:45:54 by syoun             #+#    #+#             */
/*   Updated: 2024/04/20 14:39:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_append(char *storage, char *accum)
{
	char	*joined;

	joined = ft_strjoin(accum, storage);
	free(storage);
	return (joined);
}

void	*ft_read_line(int fd, char *accum)
{
	char	*storage;
	ssize_t	bytes_read;

	if (!accum)
		accum = ft_calloc(1, 1);
	storage = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!storage)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !(ft_strchr(storage, '\n')))
	{
		bytes_read = read(fd, storage, BUFFER_SIZE);
		storage[bytes_read] = '\0';
		accum = ft_append (storage, accum);
		if (bytes_read == -1)
		{
			free(storage);
			free(accum);
		}
	}
	free(storage);
	return (accum);
}

char	*ft_cut_out(char *buffer)
{
	char	*store_the_line;
	char	*cursor;
	int		i;

	i = 0;
	store_the_line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!store_the_line)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		store_the_line[i] = buffer[i];
		i++;
	}
	store_the_line[i] = '\0';
	if (ft_strchr(buffer, '\n'))
	{
		cursor = ft_strchr(buffer, '\n');
		store_the_line = ft_substr(buffer, 0, cursor - buffer);
	}
	return (store_the_line);
}

char	*free_line(char *buffer)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (buffer[++i])
		str[j++] = buffer[i];
	str[j] = '\0';
	free (buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char *line[1024];
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read == 0)
		return (NULL);
	line[fd] = ft_cut_out(ft_read_line(fd, line[fd]));
	return (line[fd]);
}
