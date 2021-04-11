/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemes-f <llemes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:01:26 by llemes-f          #+#    #+#             */
/*   Updated: 2021/04/11 16:45:58 by llemes-f         ###   ########.fr       */
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
	ssize_t		r;
	char		bf[BUFFER_SIZE + (r = 1)];
	static char	*c_line = NULL;
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	c_line == NULL ? c_line = ft_createstr(0) : NULL;
	while (!ft_strchr(c_line, '\n') && (r = read(fd, bf, BUFFER_SIZE)) > 0)
	{
		bf[r] = '\0';
		tmp = ft_strjoin(c_line, bf);
		ft_memfdel((void **)&c_line);
		c_line = tmp;
	}
	if (r == 0)
		*line = ft_strdup(c_line);
	else if (r > 0)
		*line = ft_substr(c_line, 0, (ft_strchr(c_line, '\n') - c_line));
	else
		return (-1);
	tmp = ft_strdup(c_line + (ft_strlen(*line) + ((r > 0) ? +1 : +0)));
	ft_memfdel((void **)&c_line);
	c_line = tmp;
	return (r == 0 ? 0 * ft_memfdel((void **)&c_line) : 1);
}
