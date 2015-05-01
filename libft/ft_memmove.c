/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:09:27 by lsirigna          #+#    #+#             */
/*   Updated: 2015/02/18 16:09:32 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;
	int				i;

	tmp_s1 = (unsigned char*)s1;
	tmp_s2 = (unsigned char*)s2;
	if (tmp_s2 < tmp_s1)
	{
		i = n - 1;
		while (i >= 0)
		{
			*(tmp_s1 + i) = *(tmp_s2 + i);
			i--;
		}
	}
	else
		ft_memcpy(s1, s2, n);
	return (s1);
}
