/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:04:52 by lsirigna          #+#    #+#             */
/*   Updated: 2015/02/18 16:04:58 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	new->next = *alst;
	*alst = new;
}

void	ft_printlst(t_list **alst)
{
	t_list	*tmp;

	tmp = *alst;
	while (tmp != NULL)
	{
		ft_putendl(tmp->content);
		tmp = tmp->next;
	}
}

void	ft_lstaddend(t_list **alst, char *buff)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *alst;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	tmp2 = (t_list *)malloc(sizeof(t_list));
	tmp2->content = ft_strdup(buff);
	tmp2->next = NULL;
	if (!tmp)
		*alst = tmp2;
	else
		tmp->next = tmp2;
}
