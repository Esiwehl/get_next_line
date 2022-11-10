/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 21:01:32 by ewehl         #+#    #+#                 */
<<<<<<< Updated upstream
<<<<<<< Updated upstream
/*   Updated: 2022/11/08 18:22:44 by ewehl         ########   odam.nl         */
=======
/*   Updated: 2022/11/10 16:08:43 by ewehl         ########   odam.nl         */
>>>>>>> Stashed changes
=======
/*   Updated: 2022/11/10 16:08:43 by ewehl         ########   odam.nl         */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			if (!tmp)
				return (puts("Here"), free(nxtline), nxtline[0] = 0, NULL);
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
		if (!line)
			return (NULL);
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
	char		*checknl;
	char		*ret_line;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	line = read_lines(line, fd);
	if (!line)
		return (NULL);
	ret_line = put_newline(line);
	if (!ret_line)
		return (NULL);
	checknl = get_nxt(line);
	printf("check = %s\n", checknl);
	printf("line = %s\n", line);
	printf("nl = %s\n", !checknl ? "true" : "false");
	printf("line = %s\n", !line ? "true" : "false");
	if (!checknl && !line[0])
		return (, NULL);
	line = checknl;
	printf("line = %s\n", line);
	printf("ret_line = %s\n", ret_line);
	return (ret_line);
}

#include <fcntl.h>
int	main(void)
{ 
	const int	fd1 = open("foo.txt", O_RDONLY);
	const int	fd2 = open("foo.txt", O_RDONLY);
	// char 		*str = "cheese";
	char *gnl;

	if (fd1 < 0){
		printf("I failed you\n");
		printf("I failed you\n");}
	else{
		printf("Opened fd:: %d\n", fd1);}
		// printf("Opened fd:: %d\n", fd2);}
	
	// while (str)
	// {
	// 	str = get_next_line(fd1);
	// 	printf("fd1:: %s\n", str);
	// 	free(str);
	// 	str = get_next_line(fd2);
	// 	printf("fd2:: %s\n", str);
	// 	free(str);
	// }

	// gnl = get_next_line(fd1);
	// printf("1 GNL ret:: %s\n", gnl);
	// // char c = 0; read(fd1, &c, 1); printf("c = %c\n", c);
	// free(gnl);
	// gnl = get_next_line(fd2);
	// printf("2 GNL ret:: %s\n", gnl);
	// free(gnl);
	
	if (close(fd1) < 0) 
		printf("Closed unsuccesfully :D\n");
	else
		printf("Closed succesfully :D\n");
	system("leaks -q run");
}

//	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=10 *.c -o run 
//	-fsanitize=address -g && ./run
