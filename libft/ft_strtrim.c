/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:23:22 by lsirigna          #+#    #+#             */
/*   Updated: 2015/02/18 16:23:28 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	unsigned int	first;
	unsigned int	last;

	first = 0;
	if (s)
	{
		if (!ft_isspace(s[0]) || !ft_isspace(s[ft_strlen(s) - 1]))
			return (strdup(s));
		last = ft_strlen(s) - 1;
		while (s[first] && ft_isspace(s[first]))
			first++;
		while (last > 0 && ft_isspace(s[last]))
			last--;
		if (last < first)
			return (ft_strnew(0));
		return (ft_strsub(s, first, last - first + 1));
	}
	return (ft_strnew(0));
}
