/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <atari.h>

double		ft_abs(double v)
{
	return ((v < 0) ? -v : v);
}

double		ft_sqrt(const double fg)
{
	double	n;
	double	lstx;

	n = fg / 2.0;
	lstx = 0.0;
	while (n != lstx)
	{
		lstx = n;
		n = (n + fg / n) / 2.0;
	}
	return (n);
}

// double		ft_sin(const double x)
// {
//     const float B = 4 / M_PI;
//     const float C = -4 / (M_PI*M_PI);

//     return -(B * x + C * x * ((x < 0) ? -x : x));
// }

double ft_sin(double x)
{
	static double tab[10];

    tab[0] = x * x;
    tab[1] = tab[0]*tab[0];
    tab[2] = x * (1.0 - tab[0] / (2 * 3));
    tab[3] = x * tab[1];
    tab[4] = tab[3] * (1.0 - tab[0] / (6 * 7)) / (1.0 * 2 * 3 * 4 * 5);
    tab[5] = tab[3] * tab[1];
    tab[6] = tab[5] * (1.0 - tab[0] / (10 * 11)) /
    				(1.0 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9);
    tab[7] = tab[5] * tab[1];
    tab[8] = tab[7] * (1.0 - tab[0] / (14 * 15)) /
    				(1.0 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12 * 13);
    tab[9] = tab[8];
    tab[9] += tab[6];
    tab[9] += tab[4];
    tab[9] += tab[2];
    return (tab[9]);
}