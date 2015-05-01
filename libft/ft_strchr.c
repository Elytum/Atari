/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:17:26 by lsirigna          #+#    #+#             */
/*   Updated: 2015/02/18 16:17:31 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	letter;
	int		i;

	i = 0;
	letter = (char)c;
	while (s[i] && s[i] != letter)
		i++;
	if (s[i] == letter)
		return (&((char*)s)[i]);
	return (0);
}
