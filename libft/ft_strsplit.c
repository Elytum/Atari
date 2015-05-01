/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:22:42 by lsirigna          #+#    #+#             */
/*   Updated: 2015/02/18 16:22:46 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strclen(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int		ft_countsplit(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		else if (i == 0 && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static int		ft_alloc(char **line, char const *s, int *i, char c)
{
	int		k;

	k = 0;
	*line = (char*)malloc(sizeof(char) * (ft_strclen(s, c) + 1));
	if (!(*line))
		return (1);
	while (s[*i] != c && s[*i])
		(*line)[k++] = s[(*i)++];
	(*line)[k] = '\0';
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	tab = (char**)malloc(sizeof(char*) * (ft_countsplit(s, c)));
	if (!tab)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			if (ft_alloc(tab + j, s, &i, c))
				return (0);
			j++;
			if (!s[i])
				break ;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}
