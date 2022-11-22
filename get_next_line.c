/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/20 17:58:53 by ewehl         #+#    #+#                 */
/*   Updated: 2022/11/22 15:39:22 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

ssize_t	schmove(char *buff, size_t start)
{
	size_t	idx;
	size_t	len;
	char	*tmp;

	idx = 0;
	if (!buff)
		return (-1);
	len = ft_strlen(buff);
	tmp = malloc(len + 1);
	if (!tmp)
		return (-1);
	ft_strcpy(tmp, buff);
	buff = ft_bzero(buff, len);
	while (tmp[start + idx])
	{
		buff[idx] = tmp[start + idx];
		idx++;
	}
	free(tmp);
	return (ft_strlen(buff));
}

char	*ft_strappend(char *dst, char *src)
{
	char	*nw_str;
	size_t	idx;
	size_t	jdx;

	if (!src)
		return (NULL);
	if (!dst)
	{
		dst = ft_strldup(src, ft_strlen(src));
		if (!dst)
			return (NULL);
		return (dst);
	}
	nw_str = malloc(ft_strlen(src) + ft_strlen(dst) + 1);
	if (!nw_str)
		return (NULL);
	ft_strcpy(nw_str, dst);
	idx = ft_strlen(dst);
	jdx = 0;
	while (src[jdx])
		nw_str[idx++] = src[jdx++];
	nw_str[idx] = '\0';
	return (free(dst), nw_str);
}

char	*get_input(int fd, char *line)
{
	char	buff[BUFFER_SIZE + 1];
	char	*another_tmp;
	ssize_t	bytes_read;
	size_t	pos_nl;
	char	*tmp;

	pos_nl = 0;
	tmp = line;
	bytes_read = 1;
	while (!pos_nl && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(tmp), NULL);
		buff[bytes_read] = '\0';
		pos_nl = ft_find_nl(buff);
		another_tmp = ft_strappend(tmp, buff);
		if (!another_tmp)
			return (free(tmp), tmp = NULL, NULL);
		tmp = another_tmp;
	}
	if (!tmp[0])
		return (free(tmp), tmp = NULL);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*ret_line;
	size_t		pos_nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pos_nl = 0;
	holder = get_input(fd, holder);
	if (!holder)
		return (NULL);
	pos_nl = ft_find_nl(holder);
	if (pos_nl)
	{
		ret_line = ft_strldup(holder, pos_nl);
		if (ret_line && schmove(holder, pos_nl) != -1)
			return (ret_line);
		return (free(holder), free(ret_line), holder = NULL, NULL);
	}
	ret_line = ft_strldup(holder, ft_strlen(holder));
	if (ret_line && schmove(holder, ft_strlen(holder)) != -1)
		return (ret_line);
	return (free(holder), free(ret_line), holder = NULL, NULL);
}

// FAILS TO CHECK::
//		schmove mallocing tmp fails
//		if schmove returns (0)
//		check strldup if malloc fails.