/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bricks_col.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <atari.h>

static char			ft_collision_left(t_env *e, int i, int j)
{
	static double	t;

	e->fx = -1 + j * e->sx;
	e->fy = 1 - (i + 1) * e->sy;
	if (e->pasballx < e->fx + e->px && e->posballx > e->fx + e->px)
	{
		t = (((e->posbally - e->pasbally) / (e->posballx - e->pasballx)) *
			(e->fx + e->px - e->pasballx)) + e->pasbally;
		if (e->fy + e->py <= t && e->fy + e->sy - e->py >= t)
		{
			e->posbally = t;
			e->posballx = e->fx + e->px;
			e->vecballx = -e->vecballx;
			if (e->map[i][j] > 1)
				e->map[i][j]--;
			e->speed *= 1.00005;
			ft_playsound(BLOCK_DESTRUCT);
			return (1);
		}
	}
	return (0);
}

static char			ft_collision_right(t_env *e, int i, int j)
{
	static double	t;

	if (e->pasballx > e->fx + e->sx - e->px &&
		e->posballx < e->fx + e->sx - e->px)
	{
		t = (((e->posbally - e->pasbally) / (e->posballx - e->pasballx)) *
			(e->fx + e->sx - e->px - e->pasballx)) + e->pasbally;
		if (e->fy + e->py <= t && e->fy + e->sy - e->py >= t)
		{
			e->posbally = t;
			e->posballx = e->fx + e->sx - e->px;
			e->vecballx = -e->vecballx;
			if (e->map[i][j] > 1)
				e->map[i][j]--;
			e->speed *= 1.00005;
			ft_playsound(BLOCK_DESTRUCT);
			return (1);
		}
	}
	return (0);
}

static char			ft_collision_down(t_env *e, int i, int j)
{
	static double	t;

	if (e->pasbally < e->fy + e->py && e->posbally > e->fy + e->py)
	{
		t = (((e->posballx - e->pasballx) / (e->posbally - e->pasbally)) *
			(e->fy + e->py - e->pasbally)) + e->pasballx;
		if (t >= e->fx + e->px && e->fx + e->sx - e->px >= t)
		{
			e->posballx = t;
			e->posbally = e->fy + e->py;
			e->vecbally = -e->vecbally;
			if (e->map[i][j] > 1)
				e->map[i][j]--;
			e->speed *= 1.00005;
			ft_playsound(BLOCK_DESTRUCT);
			return (1);
		}
	}
	return (0);
}

static char			ft_collision_up(t_env *e, int i, int j)
{
	static double	t;

	if (e->pasbally > e->fy + e->sy - e->py &&
		e->posbally < e->fy + e->sy - e->py)
	{
		t = (((e->posballx - e->pasballx) / (e->posbally - e->pasbally)) *
			(e->fy + e->sy - e->py - e->pasbally)) + e->pasballx;
		if (e->fx + e->px <= t && e->fx + e->sx - e->px >= t)
		{
			e->posballx = t;
			e->posbally = e->fy + e->sy - e->py;
			e->vecbally = -e->vecbally;
			if (e->map[i][j] > 1)
				e->map[i][j]--;
			e->speed *= 1.00005;
			ft_playsound(BLOCK_DESTRUCT);
			return (1);
		}
	}
	return (0);
}

void				ft_check_collision(t_env *e)
{
	int				i;
	int				j;

	e->sx = 2 / (double)ft_strlen(e->map[0]);
	e->px = e->sx / 42;
	e->sy = 0;
	while (e->map[(int)e->sy])
		e->sy++;
	e->sy = (2 / (e->sy - 1)) / 2;
	e->py = e->sy / 42;
	i = 0;
	while (e->map[i])
	{
		j = 0;
		while (e->map[i][j])
		{
			if (e->map[i][j] != 1)
			{
				ft_collision_left(e, i, j), ft_collision_right(e, i, j),
				ft_collision_down(e, i, j), ft_collision_up(e, i, j);
			}
			j++;
		}
		i++;
	}
}
