/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:46:36 by syoun             #+#    #+#             */
/*   Updated: 2024/04/17 12:14:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char    *get_next_line(int fd);
char    *ft_strjoin(char const *s1, char const *s2);
int ft_strlen(const char *str);
char    *ft_strchr(const char *s, int c);
char    *ft_read_line(int fd, char *accum);
char    *ft_cut_out(char *buffer);
char    *ft_append(char *storage, char *accum);
void    *ft_calloc(size_t nmemb, size_t size);
char    *free_line(char *accum);
char    *ft_check_null(char *str);

#endif