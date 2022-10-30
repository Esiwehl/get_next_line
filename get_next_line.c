/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 21:01:32 by ewehl         #+#    #+#                 */
/*   Updated: 2022/10/30 18:49:34 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*get_next_line(int fd)
{
	static char	*line;
	ssize_t		linelen;
	const char	buf[BUFFER_SIZE + 1];

	while()
		linelen = read(fd, buf, BUFFER_SIZE);
}


int main(void)
{
	printf("buff = %d\n", BUFFER_SIZE);
}

//	I shouldn't need to check for empty str in ft_helpers
//	Because we shouldn't even be allowed to get in there if it doesn't exist.

// Is my understanding correct that -D [name] appends
// a define of [name] to the start of my "main"
