/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemes-f <llemes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:17:26 by llemes-f          #+#    #+#             */
/*   Updated: 2021/04/13 21:17:22 by llemes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

int	main()
{
	int		fd;
	int		ret;
	char	*line;

	fd = open("/home/lucas/Desktop/42cursos/get_next_line/text.txt", O_RDONLY);
	while ((ret = get_next_line(-1, &line)) > 0)
	{
		printf("[%d] %s\n", ret, line);
		free(line);
		line = NULL;
	}
	printf("[%d] %s\n", ret, line);
	free(line);
}
