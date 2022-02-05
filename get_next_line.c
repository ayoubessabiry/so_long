/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessabir <aessabir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:21:22 by aessabir          #+#    #+#             */
/*   Updated: 2021/12/14 21:52:43 by aessabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;

	i = 0;
	s = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	ft_free(char **s)
{
	free(*s);
	*s = NULL;
}

char	*ft_line(char **str)
{
	char	*newstr;
	char	*line;
	int		i;

	i = 0;
	if (!*str || !(*str)[0])
	{
		ft_free(str);
		return (NULL);
	}
	while ((*str)[i] && ((*str)[i] != '\n'))
		i++;
	if ((*str)[i] == '\n')
	{
		line = ft_substr(*str, 0, ++i);
		newstr = ft_strdup(*str + i);
		ft_free(str);
		*str = newstr;
		return (line);
	}
	line = ft_strdup(*str);
	ft_free(str);
	return (line);
}

void	ft_read_line(int fd, char **str, char **buff)
{
	char	*tmp;
	int		isrd;

	isrd = 1;
	if (!*str)
		*str = ft_strdup("");
	while (isrd && !strchr(*str, '\n'))
	{
		isrd = read(fd, *buff, BUFFER_SIZE);
		(*buff)[isrd] = '\0';
		tmp = *str;
		*str = ft_strjoin(tmp, *buff);
		ft_free(&tmp);
	}
	ft_free(buff);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			*buff;
	int				isrd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	isrd = read(fd, buff, 0);
	if (isrd < 0)
	{
		ft_free(&buff);
		return (NULL);
	}
	ft_read_line(fd, &str, &buff);
	return (ft_line(&str));
}
