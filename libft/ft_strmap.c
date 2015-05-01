/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:20:37 by lsirigna          #+#    #+#             */
/*   Updated: 2015/02/18 16:20:42 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*map;

	i = 0;
	while (s[i])
		i++;
	map = (char*)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i])
	{
		map[i] = (*f)(s[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}
