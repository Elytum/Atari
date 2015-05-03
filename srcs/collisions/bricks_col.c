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

void	ft_check_collision(t_env *e)
{
	int		i;
	int		j;
	double	fx;
	double	sx;
	double	px;
	double	fy;
	double	sy;
	double	py;
	double	t;

	i = 0;
	sx = 2 / (double)ft_strlen(e->map[i]);
	px = sx / 42;
	sy = 0;

	while (e->map[(int)sy])
		sy++;
	sy = (2 / (sy - 1)) / 2;
	py = sy / 42;
	while (e->map[i])
	{
		j = 0;
		while (e->map[i][j])
		{
			if (e->map[i][j] != 1)
			{
				fx = -1 + j * sx;
				fy = 1 - (i + 1) * sy;
				if (e->pasballx < fx + px && e->posballx > fx + px) //LEFT
				{
					t = (((e->posbally - e->pasbally) / (e->posballx - e->pasballx)) * (fx + px - e->pasballx)) + e->pasbally;
					if (fy + py <= t && fy + sy - py >= t)
					{
						e->posbally = t;
						e->posballx = fx + px;
						e->vecballx = -e->vecballx;
						if (e->map[i][j] > 1)
							e->map[i][j]--;
						e->speed *= 1.00005;
						ft_playsound(BLOCK_DESTRUCT);
					}
				}
				if (e->pasballx > fx + sx - px && e->posballx < fx + sx - px) //RIGHT
				{
					t = (((e->posbally - e->pasbally) / (e->posballx - e->pasballx)) * (fx + sx - px - e->pasballx)) + e->pasbally;
					if (fy + py <= t && fy + sy - py >= t)
					{
						e->posbally = t;
						e->posballx = fx + sx - px;
						e->vecballx = -e->vecballx;
						if (e->map[i][j] > 1)
							e->map[i][j]--;
						e->speed *= 1.00005;
						ft_playsound(BLOCK_DESTRUCT);
					}
				}
				if (e->pasbally < fy + py && e->posbally > fy + py) //DOWN
				{
					t = (((e->posballx - e->pasballx) / (e->posbally - e->pasbally)) * (fy + py - e->pasbally)) + e->pasballx;
					if (t >= fx + px && fx + sx - px >= t)
					{
						e->posballx = t;
						e->posbally = fy + py;
						e->vecbally = -e->vecbally;
						if (e->map[i][j] > 1)
							e->map[i][j]--;
						e->speed *= 1.00005;
						ft_playsound(BLOCK_DESTRUCT);
					}
				}
				if (e->pasbally > fy + sy - py && e->posbally < fy + sy - py) //UP
				{
					t = (((e->posballx - e->pasballx) / (e->posbally - e->pasbally)) * (fy + sy - py - e->pasbally)) + e->pasballx;
					if (fx + px <= t && fx + sx - px >= t)
					{
						e->posballx = t;
						e->posbally = fy + sy - py;
						e->vecbally = -e->vecbally;
						if (e->map[i][j] > 1)
							e->map[i][j]--;
						e->speed *= 1.00005;
						ft_playsound(BLOCK_DESTRUCT);
					}
				}
			}
		    j++;	
		}
		i++;
	}
}