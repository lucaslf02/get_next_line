/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemes-f <llemes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:01:26 by llemes-f          #+#    #+#             */
/*   Updated: 2021/04/11 16:38:12 by llemes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	ssize_t	i;

	new = ft_createstr(ft_strlen(s));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		new[i] = s[i];
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != (char)c)
		if (!s[i++])
			return (NULL);
	return ((char *)&s[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL || !(ptr = (char *)malloc(ft_strlen(s1)
		+ ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s || (long int)len < 0)
		return (NULL);
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (start < ft_strlen(s) && i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int		get_next_line(int fd, char **line)
{
	ssize_t		qtd;
	static char	*line_b = NULL;
	char		*aux;
	char		buff[BUFFER_SIZE + (qtd = 1)];

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	line_b == NULL ? line_b = ft_createstr(0) : NULL;
	while ((qtd = read(fd, buff, BUFFER_SIZE)) > 0 && !ft_strchr(line_b, '\n'))
	{
		buff[qtd] = '\0';
		aux = ft_strjoin(line_b, buff);
		ft_memfdel((void **)&line_b);
		line_b = aux;
	}
	if (qtd == 0)
		*line = ft_strdup(line_b);
	else if (qtd > 0)
		*line = ft_substr(line_b, 0, (ft_strchr(line_b, '\n') - line_b));
	else
		return (-1);
	aux = ft_strdup(line_b + (ft_strlen(*line) + ((qtd > 0) ? +1 : +0)));
	ft_memfdel((void**)&line_b);
	line_b = aux;
	return (qtd == 0 ? 0 * ft_memfdel((void**)&line_b) : 1);
}
