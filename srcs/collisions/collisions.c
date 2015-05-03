/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <atari.h>

void		ft_check_collision_map(t_env *e)
{
	if (e->posballx >= 1)
	{
		e->posballx = e->posballx - ((e->posballx - 1) * 2);
		e->vecballx = -e->vecballx;
	}
	else if (e->posballx <= -1)
	{
		e->posballx = e->posballx + ((-e->posballx - 1) * 2);
		e->vecballx = -e->vecballx;
	}
	if (e->posbally >= 1)
	{
		e->posbally = e->posbally - ((e->posbally - 1) * 2);
		e->vecbally = -e->vecbally;
	}
}

static void	ft_check_collision_barre_left(t_env *e)
{
	if (e->vecballx > 0)
	{
		e->vecballx = -e->vecballx;
		if (e->vecballx > 0)
			e->vecballx += 0.005;
		else
			e->vecballx -= 0.005;
		e->vecballx *= 1.1;
	}
	else
		e->vecballx /= 1.1;
}

static void	ft_check_collision_barre_right(t_env *e)
{
	if (e->vecballx < 0)
	{
		e->vecballx = -e->vecballx;
		if (e->vecballx > 0)
			e->vecballx += 0.005;
		else
			e->vecballx -= 0.005;
		e->vecballx *= 1.1;
	}
	else
		e->vecballx /= 1.1;
}

void		ft_check_collision_barre(t_env *e)
{
	double	l;

	l = (e->transpos * 0.01);
	if (e->posbally <= -0.99 && e->posballx >=
		(l - 0.2) && e->posballx <= (l + 0.2))
	{
		e->vecbally = -e->vecbally;
		if (e->posballx <= (l - 0.1))
			ft_check_collision_barre_left(e);
		else if (e->posballx >= (l + 0.1))
			ft_check_collision_barre_right(e);
		else
			e->vecballx /= 1.2;
		e->speed *= 1.001;
	}
}
