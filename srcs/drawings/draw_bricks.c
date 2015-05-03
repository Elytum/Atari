/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bricks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <atari.h>
#include <GLFW/glfw3.h>
#include <libft.h>

static void	ft_draw_brick(t_env *e, int i, int j)
{
	glBegin(GL_QUADS);
	e->fx = -1 + j * e->sx;
	e->fy = 1 - (i + 1) * e->sy;
	if (e->map[i][j] == 2)
		ft_draw_brick_2(e);
	else if (e->map[i][j] == 3)
		ft_draw_brick_3(e);
	else if (e->map[i][j] == 4)
		ft_draw_brick_4(e);
	else if (e->map[i][j] == 5)
		ft_draw_brick_5(e);
	else if (e->map[i][j] == -1)
		ft_draw_brick__1(e);
	else if (e->map[i][j] == -2)
		ft_draw_brick__2(e);
	else if (e->map[i][j] == -3)
		ft_draw_brick__3(e);
	glEnd();
}

void		ft_draw_bricks(t_env *e)
{
	int		i;
	int		j;

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
				ft_draw_brick(e, i, j);
			j++;
		}
		i++;
	}
}
