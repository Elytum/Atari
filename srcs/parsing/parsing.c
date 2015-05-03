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

void			print_map(t_env *e)
{
	int			i;
	int			j;
	char		lol;

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

void			ft_blocks_count(t_env *e)
{
	char		**ptr;
	char		*p;

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

char			*ft_get_path(t_env *e)
{
	char		id;

	id = e->id++;
	if (e->id == 0)
		return ("./level/0.lvl");
	if (e->id == 1)
		return ("./level/1.lvl");
	if (e->id == 2)
		return ("./level/2.lvl");
	if (e->id == 3)
		return ("./level/3.lvl");
	if (e->id == 4)
		return ("./level/4.lvl");
	if (e->id == 5)
		return ("./level/5.lvl");
	if (e->id == 6)
		return ("./level/6.lvl");
	if (e->id == 7)
		return ("./level/7.lvl");
	if (e->id == 8)
		return ("./level/8.lvl");
	if (e->id == 9)
		return ("./level/9.lvl");
	write (1, "No more maps, congratulation !\n", 31), exit(EXIT_FAILURE);
	return ("./level/0.lvl");
}

void			seek_map(t_env *e, char *path)
{
	int			fd;
	int			nbl;
	int			i;
	char		*line;

	if ((fd = open(path, O_RDONLY)) <= 0)
		write(1, "Map does not exist\n", 19), exit (-1);
	i = 0;
	while (gnl(fd, &line) > 0)
	{
		if (i == 0)
			nbl = ft_strlen(line);
		else if (nbl != (int)ft_strlen(line) && *line)
			write(1, "Invalid map\n", 12), close(fd), exit(-1);
		e->map[i] = ft_strdup(line), i++, free(line);
	}
	free(line);
	e->map[i] = NULL, close(fd);
}

void			get_map(t_env *e)
{
	char		*line;
	int			fd;
	int			nbl;
	char		*path;

	path = ft_get_path(e);
	nbl = 0;
	if ((fd = open(path, O_RDONLY)) <= 0)
		exit(-1);
	while (gnl(fd, &line) > 0)
		nbl++, free(line);
	free(line);
	close(fd);
	if (!(e->map = (char **)malloc(sizeof(char *) * (nbl + 1))))
		exit(-1);
	seek_map(e, path);
	ft_blocks_count(e);
}
