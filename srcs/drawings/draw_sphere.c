/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <atari.h>
#include <unistd.h>

void					draw_circle(float x, float y, float radius)
{
	static const int	circle_points = 100;
	static const float	angle = 2.0f * 3.1416f / circle_points;
	int					i;
	double				angle1;

	glPushMatrix();
	glTranslatef(x, y, 0.0f);
	glBegin(GL_POLYGON);
	angle1 = 0.0;
	glColor3f(0.f, 1.f, 0.f);
	glVertex2d(radius * ft_cos(0.0), radius * ft_sin(0.0));
	i = 0;
	while (i < circle_points)
	{
		glVertex2d(radius * ft_cos(angle1), radius * ft_sin(angle1));
		angle1 += angle;
		i++;
	}
	glEnd();
	glPopMatrix();
}

void					ft_launched_sphere(t_env *e)
{
	double				r;

	e->vecbally -= 0.000002;
	if (e->vecbally < 0)
	{
		e->speed *= 1.001;
		e->vecbally *= 1.0000005;
	}
	else
	{
		e->speed /= 1.0009975;
		e->vecballx *= 1.0000005;
	}
	if (e->speed < 0.25)
		e->speed = 0.25;
	r = ft_sqrt(e->vecballx * e->vecballx + e->vecbally * e->vecbally);
	e->vecballx = e->vecballx / r;
	e->vecbally = e->vecbally / r;
	e->pasballx = e->posballx;
	e->pasbally = e->posbally;
	e->posballx += e->vecballx / 400 * e->speed;
	e->posbally += e->vecbally / 400 * e->speed;
}

void					ft_draw_sphere(t_env *e)
{

	if (e->launched)
		ft_launched_sphere(e);
	else
	{
		e->posballx = e->transpos * 0.01f;
		e->posbally = -0.98;
	}
	draw_circle(e->posballx, e->posbally, e->r);
}
