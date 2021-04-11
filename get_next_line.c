/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemes-f <llemes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:01:26 by llemes-f          #+#    #+#             */
/*   Updated: 2021/04/11 16:52:34 by llemes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*s_aux;
	int		len;
	int		i;

	len = ft_strlen(s) + 1;
	s_aux = (char *)malloc(len * sizeof(char));
	if (!s_aux)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_aux[i] = s[i];
		i++;
	}
	s_aux[i] = '\0';
	return (s_aux);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*join_res;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	join_res = join;
	while (*s1)
	{
		*join = *s1;
		join++;
		s1++;
	}
	while (*s2)
	{
		*join = *s2;
		join++;
		s2++;
	}
	*join = '\0';
	return (join_res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	if (!(substr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start > s_len)
	{
		substr[0] = '\0';
		return (substr);
	}
	while (i < len && start < s_len)
		substr[i++] = s[start++];
	substr[len] = '\0';
	return (substr);
}

int		get_next_line(int fd, char **line)
{
	ssize_t		qtd;
	char		buff[BUFFER_SIZE + (qtd = 1)];
	static char	*line_b = NULL;
	char		*aux;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	line_b == NULL ? line_b = ft_createstr(0) : NULL;
	while (!ft_strchr(line_b, '\n') && (qtd = read(fd, buff, BUFFER_SIZE)) > 0)
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
