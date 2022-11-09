/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/09 19:32:12 by ewehl         #+#    #+#                 */
/*   Updated: 2022/11/09 19:41:50 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	const int	fd = open("foo.txt", O_RDONLY);
	char		*str = "a";

	while (str)
	{
		str = get_next_line(fd);
		printf("line = %s\n", str);
		free(str);
	}
	close(fd);
	system("leaks -q run");
	return (0);
}
