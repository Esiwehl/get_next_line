/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 21:40:42 by ewehl         #+#    #+#                 */
/*   Updated: 2022/10/30 19:00:59 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

char	*ft_strdup(char *s1)
{
	size_t	len;
	size_t	idx;
	char	*ret;

	idx = 0;
	len = ft_strlen(s1);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (s1[idx])
	{
		ret[idx] = s1[idx];
		idx++;
	}
	ret[idx] = '\0';
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	idx;
	char	*joined;

	idx = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!joined)
		return (NULL);
	while (s1[idx])
	{
		joined[idx] = s1[idx];
		idx++;
	}
	idx = 0;
	while (s2[idx])
	{
		joined[idx] = s2[idx];
		idx++;
	}
	joined[len1 + len2 + 1] = '\0';
	return (joined);
}
