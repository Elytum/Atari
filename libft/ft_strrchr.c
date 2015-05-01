/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:22:30 by lsirigna          #+#    #+#             */
/*   Updated: 2015/02/18 16:22:35 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	letter;
	int		i;

	i = 0;
	while (s[i])
		i++;
	letter = (char)c;
	while (i && s[i] != letter)
	{
		i--;
	}
	if (s[i] == letter)
		return ((char *)s + i);
	return (0);
}
