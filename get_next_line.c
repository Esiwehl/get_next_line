/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 21:01:32 by ewehl         #+#    #+#                 */
/*   Updated: 2022/10/31 18:37:19 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	ssize_t		bytes_read;
	// size_t		idx;
	char		buff[BUFFER_SIZE + 1];

	// idx = 0;
	bytes_read = 1;
	while (!ft_strchr(buff, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0 || !buff[0])
			return (NULL);
		// idx++;
	}
	// printf("Buff = %s\n", buff);
	line = ft_strdup(buff);
	// printf("Line = %s", line);
	return (line);
}
/*
#include <fcntl.h>
int	main(void)
{ 
	const int	fd1 = open("/Users/ewehl/francinette/tests/get_next_line/gnlTester/files/42_no_nl", O_RDWR); 
	char *gnl;

	if (fd1 < 0) 
		printf("I failed you\n");
	else
		printf("Opened fd:: %d\n", fd1); 
	gnl = get_next_line(fd1);
	// printf("GNL ret:: %s\n", gnl);
	free(gnl);
	
	if (close(fd1) < 0) 
		printf("Closed unsuccesfully :D\n");
	else
		printf("Closed succesfully :D\n"); 
}*/

// Am not appending the \n now, because strdup copies until we see \n

//	I shouldn't need to check for empty str in ft_helpers
//	Because we shouldn't even be allowed to get in there if it doesn't exist.

// Is my understanding correct that -D [name] appends
// a define of [name] to the start of my "main"

//		gcc -Wall -Werror -Wextra *.c -o run-fsanitize=address -g && ./run
