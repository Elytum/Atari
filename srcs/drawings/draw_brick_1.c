/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_brick_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GLFW/glfw3.h>
#include <atari.h>

void	ft_draw_brick__3(t_env *e)
{
	glColor3f(0, 0.5, 0);
	glVertex3f(e->fx + e->px, e->fy + e->sy - e->py, 0.f);
	glColor3f(0.5, 0, 0);
	glVertex3f(e->fx + e->px, e->fy + e->py, 0.f);
	glColor3f(0, 0, 0.5);
	glVertex3f(e->fx + e->sx - e->px, e->fy + e->py, 0.f);
	glColor3f(0, 0, 0);
	glVertex3f(e->fx + e->sx - e->px, e->fy + e->sy - e->py, 0.f);
}

void	ft_draw_brick__2(t_env *e)
{
	glColor3f(0, 0, 0);
	glVertex3f(e->fx + e->px, e->fy + e->sy - e->py, 0.f);
	glColor3f(0, 0, 0);
	glVertex3f(e->fx + e->px, e->fy + e->py, 0.f);
	glColor3f(0, 0, 0);
	glVertex3f(e->fx + e->sx - e->px, e->fy + e->py, 0.f);
	glColor3f(0, 0, 0);
	glVertex3f(e->fx + e->sx - e->px, e->fy + e->sy - e->py, 0.f);
}

void	ft_draw_brick__1(t_env *e)
{
	glColor3f(1, 1, 1);
	glVertex3f(e->fx + e->px, e->fy + e->sy - e->py, 0.f);
	glColor3f(1, 1, 1);
	glVertex3f(e->fx + e->px, e->fy + e->py, 0.f);
	glColor3f(1, 1, 1);
	glVertex3f(e->fx + e->sx - e->px, e->fy + e->py, 0.f);
	glColor3f(1, 1, 1);
	glVertex3f(e->fx + e->sx - e->px, e->fy + e->sy - e->py, 0.f);
}

void	ft_draw_brick_5(t_env *e)
{
	glColor3f(0.2f * 6.f/10.f, 0.2f * 6.f/10.f, 0.2f * 6.f/10.f);
	glVertex3f(e->fx + e->px, e->fy + e->sy - e->py, 0.f);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(e->fx + e->px, e->fy + e->py, 0.f);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(e->fx + e->sx - e->px, e->fy + e->py, 0.f);
	glColor3f(0.2f * 10.f/6.f, 0.2f * 10.f/6.f, 0.2f * 10.f/6.f);
	glVertex3f(e->fx + e->sx - e->px, e->fy + e->sy - e->py, 0.f);
}

void	ft_draw_brick_2(t_env *e)
{
	glColor3f(0.f, 0.5f * 6.f/10.f, 0.0f);
	glVertex3f(e->fx + e->px, e->fy + e->sy - e->py, 0.f);
	glColor3f(0.f, 0.5f, 0.0f);
	glVertex3f(e->fx + e->px, e->fy + e->py, 0.f);
	glColor3f(0.f, 0.5f, 0.0f);
	glVertex3f(e->fx + e->sx - e->px, e->fy + e->py, 0.f);
	glColor3f(0.f, 0.5f * 10.f/6.f, 0.0f);
	glVertex3f(e->fx + e->sx - e->px, e->fy + e->sy - e->py, 0.f);
}
