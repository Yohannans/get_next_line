/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yansquer <yansquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 04:06:00 by yansquer          #+#    #+#             */
/*   Updated: 2024/12/04 13:05:22 by yansquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_end(char *str)
{
	char	*end;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i])
		i++;
	else
	{
		free(str);
		return (NULL);
	}
	end = ft_strdup(&str[i]);
	if (!end)
		return (NULL);
	free(str);
	return (end);
}

static char	*get_start(char *str)
{
	char	*line;
	int		i;

	if (!*str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*append(char *str, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(str, buffer);
	free(str);
	return (temp);
}

static char	*get_line(int fd, char *str)
{
	char	*buffer;
	int		n;

	if (!str)
		str = ft_strdup("");
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer || !str)
		return (NULL);
	n = 1;
	while (n > 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[n] = '\0';
		str = append(str, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = get_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = get_start(str[fd]);
	str[fd] = get_end(str[fd]);
	return (line);
}
