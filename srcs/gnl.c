/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atari.h"

static void		ft_addbuf(char **save, char *buf, int ret)
{
	char	*tmp;

	tmp = *save;
	buf[ret] = '\0';
	*save = ft_strjoin(tmp, buf);
	free(tmp);
}

static void		ft_getline(char **line, char **save, int ret)
{
	size_t	len;
	char	*tmp;

	if (ret == 0 && ft_strchr(*save, 13) == NULL)
	{
		*line = *save;
		*save = ft_strnew(1);
		return ;
	}
	len = ft_strchr(*save, 13) - *save;
	*line = ft_strsub(*save, 0, len);
	tmp = *save;
	*save = ft_strsub(tmp, len + 1, ft_strlen(tmp) - len - 1);
	free(tmp);
}

static t_save	*ft_getfd(int fd, t_save **save)
{
	t_save	*tmp;

	tmp = *save;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = (t_save *)malloc(sizeof(*tmp));
	if (tmp == NULL)
		return (NULL);
	tmp->fd = fd;
	tmp->save = ft_strnew(1);
	tmp->next = *save;
	*save = tmp;
	return (tmp);
}

static void		ft_delfd(int fd, t_save **save)
{
	t_save *tmp;
	t_save *tmp2;

	tmp = *save;
	if (tmp != NULL && tmp->fd == fd)
	{
		free(tmp->save);
		*save = tmp->next;
		free(tmp);
		return ;
	}
	tmp2 = tmp->next;
	while (tmp != NULL && tmp2 != NULL)
	{
		if (tmp2->fd == fd)
		{
			free(tmp2->save);
			tmp->next = tmp2->next;
			free(tmp2);
			return ;
		}
		tmp = tmp2;
		tmp2 = tmp->next;
	}
}

int				gnl(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static t_save	*save;
	t_save			*tmp;

	if (!line || fd < 0)
		return (-1);
	tmp = ft_getfd(fd, &save);
	if (tmp == NULL)
		return (-1);
	while (tmp->save != NULL && ft_strchr(tmp->save, 13) == NULL
		&& ((ret = read(fd, buf, BUFF_SIZE)) > 0))
		ft_addbuf(&(tmp->save), buf, ret);
	if (ret == -1 || tmp->save == NULL)
		return (-1);
	if ((tmp->save)[0] == '\0' && ret == 0)
	{
		ft_delfd(fd, &save);
		*line = ft_strnew(0);
		return (0);
	}
	ft_getline(line, &(tmp->save), ret);
	return (1);
}
