/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atari.h"
#include <fcntl.h>

void		print_map(t_env *e)
{
	int		i;
	int		j;
	char	lol;

	i = 0;
	while (e->map[i])
	{
		j = 0;
		while (e->map[i][j])
		{
			lol = e->map[i][j] + 47;
			write(1, &lol, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void		get_map(t_env *e, int fd, char *file)
{
	int		nbl;
	char	**map;
	char	*line;
	int		i;

	nbl = 0;
	fd = open(file, O_RDONLY);
	while (gnl(fd, &line) > 0)
		nbl++, free(line);
	close(fd);
	map = (char **)malloc(sizeof(char *) * (nbl + 1));
	i = 0;
	if ((fd = open(file, O_RDONLY)) <= 0)
		write(1, "Map does not exist\n", 19), exit (-1);
	while (gnl(fd, &line) > 0)
	{
		if (i == 0)
			nbl = ft_strlen(line);
		else if (nbl != (int)ft_strlen(line) && *line)
			write(1, "Invalid map\n", 12), close(fd), exit(-1);
		map[i] = ft_strdup(line);
		i++, free(line);
	}
	map[i] = NULL, close(fd);
	e->map = map;
}
