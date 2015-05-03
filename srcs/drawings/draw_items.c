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

void		ft_draw_pad(t_env *e)
{
	glPushMatrix();
	glTranslatef((double)e->transpos * 0.01f, 0.f, 0.f);
	glBegin(GL_LINES);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(-0.2f, -0.99f, 0.f);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(0.2f, -0.99f, 0.f);
	glEnd();
	glPopMatrix();
}

void		ft_draw_background(void)
{
	glBegin(GL_QUADS);
	glColor3f(0.f, 0.f, 0.2f);
	glVertex3f(-1.f, -1.f, 0.f);
	glColor3f(0.f, 0.f, 0.3f);
	glVertex3f(1.f, -1.f, 0.f);
	glColor3f(0.f, 0.f, 0.1f);
	glVertex3f(1.f, 1.f, 0.f);
	glColor3f(0.f, 0.f, 0.1f);
	glVertex3f(-1.f, 1.f, 0.0f);
	glEnd();
}
