/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:04:20 by lsirigna          #+#    #+#             */
/*   Updated: 2015/02/18 16:04:27 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		ft_pow(long n, int pow)
{
	long	result;

	result = 1;
	while (pow)
	{
		result *= n;
		pow--;
	}
	return (result);
}

static int		ft_abs(int n)
{
	if (n < 0)
		return (0 - n);
	return (n);
}

static int		ft_setnum(char **num, int size, int n, int neg)
{
	int		c;

	c = size;
	*num = (char*)malloc(size + 1);
	if (!(*num))
		return (1);
	(*num)[c] = '\0';
	c--;
	while (c >= neg)
	{
		(*num)[c] = (ft_abs(n % 10)) + '0';
		c--;
		n /= 10;
	}
	if (neg)
		(*num)[c] = '-';
	return (0);
}

char			*ft_itoa(int n)
{
	int		mul;
	int		neg;
	char	*num;

	mul = 0;
	neg = 0;
	while ((int)((long)n / ft_pow(10, mul)))
		mul++;
	if (n < 0)
		neg = 1;
	if (n == 0)
	{
		num = (char*)malloc(2);
		num[0] = '0';
		num[1] = '\0';
	}
	else
	{
		if (ft_setnum(&num, mul + neg, n, neg))
			return (0);
	}
	return (num);
}
