/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 21:01:32 by ewehl         #+#    #+#                 */
/*   Updated: 2022/11/08 13:42:26 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*put_newline(char *arr)
{
	char		*tmp;
	size_t		idx;

	idx = 0;
	if (!arr[idx])
	{
		free(arr);
		return (NULL);
	}
	while (arr[idx] != '\n' && arr[idx] != '\0')
		idx++;
	tmp = ft_substr(arr, 0, idx + 1);
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}

char	*get_nxt(char *arr)
{
	int		idx;
	char	*tmp;

	idx = 0;
	while (arr[idx])
	{
		if (arr[idx] == '\n')
		{
			tmp = ft_strdup(&arr[idx + 1]);
			free(arr);
			return (tmp);
		}
		idx++;
	}
	if (!arr[idx])
		free(arr);
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
/*
#include <fcntl.h>
int	main(void)
{ 
	const int	fd1 = open("foo.txt", O_RDONLY);
	// const int	fd2 = open("get_next_line.c", O_RDONLY);
	char 		*str = "cheese";
	// char *gnl;

	if (fd1 < 0){
		printf("I failed you\n");
		printf("I failed you\n");}
	else{
		printf("Opened fd:: %d\n", fd1);}
		// printf("Opened fd:: %d\n", fd2);}
	
	while (str)
	{
		str = get_next_line(fd1);
		printf("fd1: %s\n", str);
		free(str);
		// str = get_next_line(fd2);
		// printf("fd2:: %s", str);
		// free(str);
	}

	// gnl = get_next_line(fd1);
	// printf("1 GNL ret:: %s\n", gnl);
	// free(gnl);
	// gnl = get_next_line(fd1);
	// printf("2 GNL ret:: %s\n", gnl);
	// free(gnl);
	
	if (close(fd1) < 0) 
		printf("Closed unsuccesfully :D\n");
	else
		printf("Closed succesfully :D\n");
	system("leaks -q run");
}
*/

//	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=10 *.c -o run 
//	-fsanitize=address -g && ./run
