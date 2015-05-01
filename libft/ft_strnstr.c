/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:22:19 by lsirigna          #+#    #+#             */
/*   Updated: 2015/02/18 16:22:23 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				j;
	unsigned int	k;

	i = 0;
	if (!s2[i])
		return ((char*)s1);
	while (i < n && s1[i])
	{
		if (s1[i] == s2[0])
		{
			k = i;
			j = 0;
			while (s2[j] && s1[k] && s1[k] == s2[j] && k < n)
			{
				k++;
				j++;
			}
			if (!s2[j])
				return ((char*)s1 + i);
		}
		i++;
	}
	return (0);
}
