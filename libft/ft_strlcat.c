/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:20:05 by lsirigna          #+#    #+#             */
/*   Updated: 2015/02/18 16:20:10 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	j;
	int				i;
	int				k;
	unsigned int	len;

	i = 0;
	j = 0;
	k = 0;
	while (src[k])
		k++;
	while (dst[j])
	{
		if (j >= size)
			return (size + k);
		j++;
	}
	if (j >= size)
		return (size + k);
	len = (unsigned int)(j + k);
	while (j < (size - 1) && src[i])
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (len);
}
