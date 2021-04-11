/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemes-f <llemes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:01:09 by llemes-f          #+#    #+#             */
/*   Updated: 2021/04/11 16:41:53 by llemes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "get_next_line.h"

size_t		ft_strlen(char const *s)
{
	const	char	*ptr;
	size_t			count;

	count = 0;
	ptr = s;
	while (*ptr)
	{
		++ptr;
		++count;
	}
	return (count);
}

char		*ft_strnew(size_t length)
{
	return (ft_memalloc((length + 1) * sizeof(char)));
}

void		*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}

void		*ft_memset(void *s, int c, size_t length)
{
	unsigned	char	*ub;

	ub = (unsigned char *)s;
	while (length > 0)
	{
		*ub = c;
		length--;
		ub++;
	}
	return (s);
}

int			ft_memdel(void **ptr)
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
