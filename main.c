/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoun <syoun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:52:01 by syoun             #+#    #+#             */
/*   Updated: 2023/10/25 20:05:55 by syoun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main()
{
	int fd = open("example.txt", O_RDONLY);
	if (fd == -1)
		return (1);

	char buffer[1024];
	ssize_t bytes_read;

	bytes_read = read(fd, buffer, sizeof(buffer));

	if (bytes_read == -1)
	{
		return (1);
	}
	close(fd);
	return (0);
}
