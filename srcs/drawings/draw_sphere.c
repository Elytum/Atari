/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <atari.h>
#include <GLFW/glfw3.h>
#include <math.h>

// static void			ft_draw_sphere_part3(t_env *e)
// {
// 	glNormal3f( e->slice_r1 * cos(e->theta), e->y1, e->slice_r1 * sin(e->theta) );
// 	glVertex3f( e->slice_r1 * cos(e->theta) / (1 / e->r), e->y1/ (1 / e->r), e->slice_r1 * sin(e->theta) / (1 / e->r));
// 	glNormal3f( e->slice_r0 * cos(e->theta), e->y0, e->slice_r0 * sin(e->theta) );
// 	glVertex3f( e->slice_r0 * cos(e->theta) / (1 / e->r), e->y0/ (1 / e->r), e->slice_r0 * sin(e->theta) / (1 / e->r));
// 	glNormal3f( e->slice_r1 * cos(e->theta1), e->y1, e->slice_r1 * sin(e->theta1) );
// 	glVertex3f( e->slice_r1 * cos(e->theta1) / (1 / e->r), e->y1/ (1 / e->r), e->slice_r1 * sin(e->theta1)/ (1 / e->r));
// 	glNormal3f( e->slice_r1 * cos(e->theta1), e->y1, e->slice_r1 * sin(e->theta1) );
// 	glVertex3f( e->slice_r1 * cos(e->theta1) / (1 / e->r), e->y1/ (1 / e->r), e->slice_r1 * sin(e->theta1)/ (1 / e->r));
// 	glNormal3f( e->slice_r0 * cos(e->theta), e->y0, e->slice_r0 * sin(e->theta) );
// 	glVertex3f( e->slice_r0 * cos(e->theta) / (1 / e->r), e->y0/ (1 / e->r), e->slice_r0 * sin(e->theta) / (1 / e->r));
// 	glNormal3f( e->slice_r0 * cos(e->theta1), e->y0, e->slice_r0 * sin(e->theta1) );
// 	glVertex3f( e->slice_r0 * cos(e->theta1) / (1 / e->r), e->y0/ (1 / e->r), e->slice_r0 * sin(e->theta1)/ (1 / e->r));
// }

// static void			ft_draw_sphere_part2(t_env *e)
// {
// 	e->slices = 20;
// 	e->delta_eta = M_PI / e->slices;

// 	glBegin(GL_TRIANGLES);
// 	glColor3f(1.f, 0.f, 0.f);
// 	e->eta0 = 0;
// 	while (e->eta0 < M_PI - 0.0001 - e->delta_eta)
// 	{
// 		e->eta1 = e->eta0 + e->delta_eta;
// 		e->y0 = cos(e->eta0), e->y1 = cos(e->eta1);
// 		e->slice_r0 = sin(e->eta0), e->slice_r1 = sin(e->eta1);
// 		e->delta_theta = e->delta_eta * e->slice_r1;
// 		e->theta = 0;
// 		while (e->theta < 2 * M_PI)
// 		{
// 			e->theta1 = e->theta + e->delta_theta;
// 			ft_draw_sphere_part3(e);
// 			e->theta += e->delta_theta;
// 		}
// 		e->eta0 += e->delta_eta;
// 	}
// 	glEnd();
// 	glPopMatrix();

// }

static void			ft_draw_sphere_part2(t_env *e)
{
	e->slices = 20;
	e->delta_eta = M_PI / e->slices;

	glBegin(GL_TRIANGLES);
	glColor3f(1.f, 0.f, 0.f);
	e->eta0 = 0;
	while (e->eta0 < M_PI - 0.0001 - e->delta_eta)
	{
		e->eta1 = e->eta0 + e->delta_eta;
		const double y0 = cos(e->eta0);
		const double y1 = cos(e->eta1);
		const double slice_r0 = sin(e->eta0);
		const double slice_r1 = sin(e->eta1);
		const double delta_theta = e->delta_eta * slice_r1;
		double theta = 0;
		while (theta < 2 * M_PI)
		{
			const double theta1 = theta + delta_theta;

			glNormal3f( slice_r1 * cos(theta), y1, slice_r1 * sin(theta) );
			glVertex3f( slice_r1 * cos(theta) / (1 / e->r), y1/ (1 / e->r), slice_r1 * sin(theta) / (1 / e->r));
			glNormal3f( slice_r0 * cos(theta), y0, slice_r0 * sin(theta) );
			glVertex3f( slice_r0 * cos(theta) / (1 / e->r), y0/ (1 / e->r), slice_r0 * sin(theta) / (1 / e->r));
			glNormal3f( slice_r1 * cos(theta1), y1, slice_r1 * sin(theta1) );
			glVertex3f( slice_r1 * cos(theta1) / (1 / e->r), y1/ (1 / e->r), slice_r1 * sin(theta1)/ (1 / e->r));
			glNormal3f( slice_r1 * cos(theta1), y1, slice_r1 * sin(theta1) );
			glVertex3f( slice_r1 * cos(theta1) / (1 / e->r), y1/ (1 / e->r), slice_r1 * sin(theta1)/ (1 / e->r));
			glNormal3f( slice_r0 * cos(theta), y0, slice_r0 * sin(theta) );
			glVertex3f( slice_r0 * cos(theta) / (1 / e->r), y0/ (1 / e->r), slice_r0 * sin(theta) / (1 / e->r));
			glNormal3f( slice_r0 * cos(theta1), y0, slice_r0 * sin(theta1) );
			glVertex3f( slice_r0 * cos(theta1) / (1 / e->r), y0/ (1 / e->r), slice_r0 * sin(theta1)/ (1 / e->r));
			theta += delta_theta;
		}
		e->eta0 += e->delta_eta;
	}
	glEnd();
	glPopMatrix();
}

void				ft_draw_sphere(t_env *e)
{
	double			r;

	e->vecbally -= 0.0000005;
	if (e->vecbally < 0)
	{
		e->speed *= 1.001;
		e->vecbally -= 0.0000005;
	}
	else
	{
		e->speed /= 1.00099;
		e->vecballx *= 1.0000005;
	}
	r = sqrt(e->vecballx * e->vecballx + e->vecbally * e->vecbally);
	e->vecballx = e->vecballx / r;
	e->vecbally = e->vecbally / r;
	e->pasballx = e->posballx;
	e->pasbally = e->posbally;
	e->posballx	+= e->vecballx / 500 * e->speed;
	e->posbally += e->vecbally / 500 * e->speed;
	glPushMatrix();
	glTranslatef((double) e->posballx * 1.0, e->posbally * 1.0, 0.f);
	ft_draw_sphere_part2(e);
}
