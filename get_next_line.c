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

	joined = ft_strjoin(storage, accum);
	free(storage);
	return (joined);
}

char	*ft_read_line(int fd, char *storage)
{
	char	*accum;
	int		bytes_read;

	if (!storage)
		storage = ft_calloc(1, 1);
	accum = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!accum)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !(ft_strchr(storage, '\n')))
	{
		bytes_read = read(fd, accum, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(storage), free(accum), NULL);
		accum[bytes_read] = '\0';
		storage = ft_append (storage, accum);
		if (!storage)
			return (NULL);
	}
	free (accum);
	return (storage);
}

char	*ft_cut_out(char *accum)
{
	char	*store_the_line;
	int		i;

	i = 0;
	if (!accum[i])
		return (NULL);
	while (accum[i] != '\0' && accum[i] != '\n')
		i++;
	store_the_line = ft_calloc(i + 2, sizeof(char));
	if (!store_the_line)
		return (NULL);
	i = 0;
	while (accum[i] != '\n' && accum[i] != '\0')
	{
		store_the_line[i] = accum[i];
		i++;
	}
	if (accum[i] == '\n' && accum[i] != '\0')
		store_the_line[i++] = '\n';
	return (store_the_line);
}

char	*free_line(char *accum)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (accum[i] && accum[i] != '\n')
		i++;
	if (!accum[i])
	{
		free (accum);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(accum) - i + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (accum[++i])
		str[j++] = accum[i];
	str[j] = '\0';
	free (accum);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*store_the_line;
	static char	*accum;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	accum = ft_read_line(fd, accum);
	if (!accum)
		return (NULL);
	store_the_line = ft_cut_out(accum);
	accum = free_line(accum);
	return (store_the_line);
}
// #include <stdio.h>
// int main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *line;
// 	while((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return(0);
// }