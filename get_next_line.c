/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 21:01:32 by ewehl         #+#    #+#                 */
/*   Updated: 2022/11/09 21:20:38 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*put_newline(char *nline)
{
	char		*tmp;
	size_t		idx;

	idx = 0;
	while (nline[idx] != '\n' && nline[idx] != '\0')
		idx++;
	tmp = ft_substr(nline, 0, idx + 1);
	return (tmp);
}

char	*get_nxt(char *nxtline)
{
	int		idx;
	char	*tmp;

	idx = 0;
	while (nxtline[idx])
	{
		if (nxtline[idx] == '\n')
		{
			tmp = ft_strdup(&nxtline[idx + 1]);
			free(nxtline);
			return (tmp);
		}
		idx++;
	}
	free(nxtline);
	return (NULL);
}

char	*read_lines(char *line, int fd)
{
	char		buff[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	bytes_read = 1;
	buff[0] = '\0';
	while (!(ft_strchr(buff, '\n')) && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(line), NULL);
		buff[bytes_read] = '\0';
		line = ft_strjoin(line, buff);
	}
	if (!line[0])
		return (free(line), NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*ret_line;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	line = read_lines(line, fd);
	if (!line)
		return (NULL);
	ret_line = put_newline(line);
	if (!ret_line)
		return (NULL);
	line = get_nxt(line);
	return (ret_line);
}

// Say in get_nxt my strdup fails, should I then not return anything
// at all, not even the string I already read? Or should I still return
// just nothing afterwards/.

//	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=10 *.c -o run 
//	-fsanitize=address -g && ./run
