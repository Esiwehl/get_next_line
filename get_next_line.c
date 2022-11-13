/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 21:01:32 by ewehl         #+#    #+#                 */
/*   Updated: 2022/11/13 16:59:52 by ewehl         ########   odam.nl         */
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
	printf("nline add:: %p\n", nline);
	printf("tmp add:: %p\n", tmp);
	return(tmp);
}

char	*get_nxt(char *nxtline)
{
	char	*tmp;

	printf("nxtline == %s", nxtline);
	tmp = ft_strchr(nxtline, '\n');
	printf("tmp == %s", tmp);
	/*while (nxtline[idx])
	{
		printf("idx = %d\n", idx);
		if (nxtline[idx] == '\n')
		{
			printf(" inside idx = %d\n", idx);
			tmp = ft_strdup(&nxtline[idx + 1]);
			return (tmp);
		}
		idx++;
	}*/
	if (*tmp == '\n' && tmp + 1)
		tmp++;
	return (tmp);
}

char	*read_lines(char *line, int fd)
{
	char		buff[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*tmp;

	bytes_read = 1;
	buff[0] = '\0';
	while (!(ft_strchr(buff, '\n')) && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(line), NULL);
		buff[bytes_read] = '\0';
		tmp = ft_strjoin(line, buff);
		line = tmp;
		free(tmp);
		if (!line)
			return (NULL);
	}
	printf("readlines tmp add:: %p\n", tmp);
	if (!line[0])
		return (free(line), NULL);
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
	printf("Start line = %s\n", line);
	tmp = line;
	if (!line)
		return (NULL);
	ret_line = put_newline(line);
	printf("retLine = %s\n", ret_line);
	if (!ret_line)
		return (NULL);
	checknl = get_nxt(tmp);
	// free(line);
	line = checknl;
	// if (!((!line && tmp) /*|| (line && tmp)*/))
	// 	return (free(ret_line), NULL);
	printf("ret_line add:: %p\n", ret_line);
	printf("line add:: %p\n", line);
	printf("End line = %s\n", line);
	return (puts("Here"), ret_line);
}

// Say in get_nxt my strdup fails, should I then not return anything
// at all, not even the string I already read? Or should I still return
// just nothing afterwards/.

//	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=10 *.c -o run 
//	-fsanitize=address -g && ./run

// gcc -Wall -Werror -Wextra -g -o1 -D BUFFER_SIZE=42 *.c -o run 
// && valgrind --leak-check=full ./run
