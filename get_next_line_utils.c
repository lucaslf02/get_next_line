/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemes-f <llemes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:01:09 by llemes-f          #+#    #+#             */
/*   Updated: 2021/04/14 20:24:55 by llemes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "get_next_line.h"

size_t		ft_strlen(char const *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_createstr(size_t length)
{
	size_t	nmemb;
	size_t	size;
	void		*ptr;

	nmemb = length + 1;
	size = sizeof(char);	
	if (!(ptr = malloc(size * nmemb)))
		return (ptr);
	ft_memset(ptr, 0, (size * nmemb));
	return (ptr);
}

size_t	ft_valid_fd(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	size_t	qtd;

	qtd = 0;
	qtd = read(fd, buff, 0);
	return (qtd);
}

void		*ft_memset(void *s, int c, size_t length)
{
	int i;

	i = 0;
	while (i < (int)length)
	{
		((char*)s)[i] = c;
		i++;
	}
	return (s);
}

int			ft_memfdel(void **ptr)
{
	if (*ptr)
	{
		ft_memset(*ptr, 0, ft_strlen(*ptr));
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
