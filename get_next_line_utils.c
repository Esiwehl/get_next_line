/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 21:40:42 by ewehl         #+#    #+#                 */
/*   Updated: 2022/11/01 15:53:29 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
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
	{
		free(ret);
		return (NULL);
	}
	while (s1[idx])
	{
		ret[idx] = s1[idx];
		idx++;
	}
	ret[idx] = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char) c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	idx;
	size_t	s1_len;
	char	*strj;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	strj = (char *)malloc(sizeof(char) * (s1_len + ft_strlen(s2) + 1));
	if (!strj)
		return (NULL);
	idx = -1;
	while (s1[++idx])
		strj[idx] = s1[idx];
	idx = -1;
	while (s2[++idx])
		strj[s1_len + idx] = s2[idx];
	strj[s1_len + idx] = '\0';
	free(s1);
	return (strj);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	idx;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
			return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	idx = 0;
	while (idx < len && s[start])
		substr[idx++] = s[start++];
	substr[idx] = '\0';
	return (substr);
}
