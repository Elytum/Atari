/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:09:40 by lsirigna          #+#    #+#             */
/*   Updated: 2015/02/18 16:09:45 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*tmp_b;
	unsigned int		i;

	i = 0;
	tmp_b = (unsigned char*)b;
	while (i < len)
	{
		*(tmp_b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
