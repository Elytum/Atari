/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:08:17 by lsirigna          #+#    #+#             */
/*   Updated: 2015/02/18 16:08:22 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*tmp_s1;
	const unsigned char		*tmp_s2;
	unsigned int			i;

	i = 0;
	tmp_s1 = (unsigned char*)s1;
	tmp_s2 = (unsigned char*)s2;
	while (i < n && tmp_s1[i] == tmp_s2[i])
		i++;
	if (i < n)
		return (tmp_s1[i] - tmp_s2[i]);
	else
	{
		if (tmp_s1[i] == tmp_s2[i])
			return (tmp_s1[i] - tmp_s2[i]);
		else
			return (0);
	}
}
