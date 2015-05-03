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

#include <atari.h>
#include <fcntl.h>
#include <libft.h>

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

void		ft_blocks_count(t_env *e)
{
	char	**ptr;
	char	*p;

	e->blocks = 0;
	ptr = e->map;
	while (*ptr)
	{
		p = *ptr;
		while (*p)
		{
			if (*p > 1 && *p <= 5)
				e->blocks++;
			p++;
		}
		ptr++;
	}
}

void		get_map(t_env *e, int fd, char *file)
{
	int		nbl;
	char	*line;
	int		i;

	nbl = 0;
	fd = open(file, O_RDONLY);
	while (gnl(fd, &line) > 0)
		nbl++, free(line);
	close(fd);
	if (!(e->map = (char **)malloc(sizeof(char *) * (nbl + 1))))
		return ;
	i = 0;
	if ((fd = open(file, O_RDONLY)) <= 0)
		write(1, "Map does not exist\n", 19), exit (-1);
	while (gnl(fd, &line) > 0)
	{
		if (i == 0)
			nbl = ft_strlen(line);
		else if (nbl != (int)ft_strlen(line) && *line)
			write(1, "Invalid map\n", 12), close(fd), exit(-1);
		e->map[i] = ft_strdup(line);
		i++, free(line);
	}
	e->map[i] = NULL, close(fd);
	ft_blocks_count(e);
}
