/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 21:01:32 by ewehl         #+#    #+#                 */
/*   Updated: 2022/11/13 11:54:34 by ewehl         ########   odam.nl         */
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
			if (!tmp)
				return (NULL);
			return (tmp);
		}
		idx++;
	}
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
			return (free(line), NULL); // Not sure if this still needs to be here...
		buff[bytes_read] = '\0';
		line = ft_strjoin(line, buff);
		if (!line)
			return (NULL);
	}
	if (!line[0])
		return (free(line),NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*ret_line;
	char		*checknl;
	char		*tmp;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	line = read_lines(line, fd);
	tmp = line;
	// printf("tmp contains:: %s\n", tmp);
	// printf("in GNL address of line after read_lines:: %p\n", line);
	if (!line)
		return (NULL);
	ret_line = put_newline(line);
	// printf("line contains :: %s\n", ret_line);
	// printf("in GNL address of ret_line:: %p\n", ret_line);
	if (!ret_line)
		return (free(line), NULL);
	checknl = get_nxt(tmp);
	// printf("checknl contains:: %s\n", checknl);
	free(line);
	line = checknl;
	// printf("tmp = %s\n", line);
	if ((!line && tmp)|| (line && tmp))
		return (ret_line);
	return (/*puts("Here"),*/free(ret_line), NULL);
}

// Say in get_nxt my strdup fails, should I then not return anything
// at all, not even the string I already read? Or should I still return
// just nothing afterwards/.

//	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=10 *.c -o run 
//	-fsanitize=address -g && ./run

// gcc -Wall -Werror -Wextra -g -o1 -D BUFFER_SIZE=42 *.c -o run 
// && valgrind --leak-check=full ./run
