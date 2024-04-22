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

static char *ft_append (char *storage, char *accum)
{
	char *joined;

	joined = ft_strjoin(accum, storage);
	free(storage);
	return (joined);
}

void	*ft_read_line(int fd, char *accum)
{
	char *storage;
	ssize_t bytes_read;

	storage = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!storage)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, storage, BUFFER_SIZE);
		if (!(ft_strchr(storage, '\n')))
			return (ft_append(storage, accum));
	}
	if (bytes_read <= 0)
	{
		free(storage);
		return(NULL);
	}
	storage[bytes_read] = '\0';
	return (ft_append(storage, accum));
}
char	*ft_extract_line(void *storage)
{
	char *line;
	int i;

	i = 0;
	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (storage[i] != '\n' && storage[i] == EOF)
	{
		i++;
		if (storage[i] == '\n')
		{
			line = ft_substr(storage, 0, i);
			return (line);
		}
	}
}
	malloc ((i + 1) * sizeof(char));
	return (line);
}

char *get_next_line(int fd)
{
	char buf[BUFFER_SIZE + 1];
	ssize_t bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read == 0)
		return (NULL);
	/*while (!ft_strchr(buf, '\n') && buf != '\0')
	{
		
	}*/
	while (cursor != \n || bytes_read > 0)
	{
		ft_read_line(fd);
	}
	return (line);

static line[1024];
