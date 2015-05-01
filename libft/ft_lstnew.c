/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:07:08 by lsirigna          #+#    #+#             */
/*   Updated: 2015/02/18 16:07:13 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*elem;

	elem = (t_list*)malloc(sizeof(t_list));
	if (!elem)
		return (0);
	if (!content)
	{
		elem->content = 0;
		elem->content_size = 0;
	}
	else
	{
		elem->content = malloc(content_size);
		ft_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
	}
	elem->next = 0;
	return (elem);
}
