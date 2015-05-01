/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:18:30 by lsirigna          #+#    #+#             */
/*   Updated: 2015/02/18 16:18:36 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*copy;
	size_t		i;
	size_t		j;

	if (s1 == NULL)
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
		j++;
	copy = (char *)malloc(sizeof(char) * j + 1);
	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (i < j)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}
