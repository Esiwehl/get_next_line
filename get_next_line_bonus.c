/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 21:01:32 by ewehl         #+#    #+#                 */
/*   Updated: 2022/11/08 15:47:51 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*put_newline(char *nline)
{
	char		*tmp;
	size_t		idx;

	idx = 0;
	if (!nline[idx])
	{
		free(nline);
		return (NULL);
	}
	while (nline[idx] != '\n' && nline[idx] != '\0')
		idx++;
	tmp = ft_substr(nline, 0, idx + 1);
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
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
	if (!nxtline[idx])
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
		{
			free(line);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		line = ft_strjoin(line, buff);
	}
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		*ret_line;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || fd > OPEN_MAX)
		return (NULL);
	line[fd] = read_lines(line[fd], fd);
	if (!line[fd])
		return (NULL);
	ret_line = put_newline(line[fd]);
	if (!ret_line)
		return (NULL);
	line[fd] = get_nxt(line[fd]);
	return (ret_line);
}
