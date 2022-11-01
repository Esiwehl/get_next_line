/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 21:01:32 by ewehl         #+#    #+#                 */
/*   Updated: 2022/11/01 15:37:37 by ewehl         ########   odam.nl         */
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
		return (NULL);
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

char	*read_lines( char *line, int fd)
{
	char		buff[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	bytes_read = 1;
	while (!ft_strchr(buff, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0 || !buff[0])
			return (NULL);
		buff[bytes_read] = '\0';
		line = ft_strjoin(line, buff);
	}
	if (!line)
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

	if (BUFFER_SIZE <= 0)
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

/*#include <fcntl.h>
int	main(void)
{ 
	const int	fd1 = open("foo.txt", O_RDWR); 
	char *gnl;

	if (fd1 < 0) 
		printf("I failed you\n");
	else
		printf("Opened fd:: %d\n", fd1); 
	gnl = get_next_line(fd1);
	printf("GNL ret:: %s\n", gnl);
	free(gnl);
	
	if (close(fd1) < 0) 
		printf("Closed unsuccesfully :D\n");
	else
		printf("Closed succesfully :D\n");
	// system("leaks run");
}*/

// Read lines (to check whether there even is \n)

// Am not appending the \n now, because strdup copies 
// until we see \n

//	I shouldn't need to check for empty str in ft_helpers
//	Because we shouldn't even be allowed to get in there 
//  if it doesn't exist.

// Is my understanding correct that -D [name] appends
// a define of [name] to the start of my "main"

//	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=10 *.c -o run 
//	-fsanitize=address -g && ./run
