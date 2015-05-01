/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:23:06 by lsirigna          #+#    #+#             */
/*   Updated: 2015/02/18 16:23:11 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*sub;

	if (start + len > ft_strlen(s))
		return (NULL);
	sub = ft_strnew(len + 1);
	if (sub == NULL)
		return (NULL);
	ft_strncpy(sub, s + start, len);
	return (sub);
}
