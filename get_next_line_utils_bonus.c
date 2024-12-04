/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 03:58:11 by yansquer          #+#    #+#             */
/*   Updated: 2024/12/04 13:02:56 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*us;

	us = (unsigned char *)s;
	i = 0;
	while (us[i] && us[i] != c % 128)
		i++;
	if (!us[i] && c % 128)
		return (NULL);
	return ((char *)us + i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen((char *)s1);
	s2 = malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s1, len + 1);
	return (s2);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (ft_strlen((char *)src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*jn;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	jn = malloc(sizeof(char) * (len1 + len2 + 1));
	if (jn == NULL)
		return (NULL);
	ft_strlcpy(jn, s1, len1 + 1);
	ft_strlcpy(jn + len1, s2, len2 + 1);
	return (jn);
}
