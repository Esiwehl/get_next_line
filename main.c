/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/09 19:32:12 by ewehl         #+#    #+#                 */
/*   Updated: 2022/11/10 15:02:44 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	const int	fd = open("foo.txt", O_RDONLY);
	char		*str = "a";
	int			p = 0;

	while (str)
	{
		p++;
		str = get_next_line(fd);
		printf("[%d] line = %s\n",p, str);
		free(str);
	}
	close(fd);
	system("leaks -q run");
	return (0);
}
