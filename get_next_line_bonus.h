/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 21:03:06 by ewehl         #+#    #+#                 */
/*   Updated: 2022/11/22 14:05:49 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);

char	*get_input(int fd, char *line);
char	*ft_strappend(char *dst, char *src);
char	*ft_strldup(char *s1, size_t len);
void	*ft_bzero(void *s, size_t n);
ssize_t	schmove(char *buff, size_t start);
size_t	ft_strlen(const char *str);
size_t	ft_strcpy(char *dest, char *src);
size_t	ft_find_nl(char *buff);

#endif
