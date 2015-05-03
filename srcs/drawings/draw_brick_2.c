/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_brick_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <atari.h>

void	ft_draw_brick_3(t_env *e)
{
	glColor3f(0.f, 0.0f, 0.5f * 6.f / 10.f);
	glVertex3f(e->fx + e->px, e->fy + e->sy - e->py, 0.f);
	glColor3f(0.f, 0.0f, 0.5f);
	glVertex3f(e->fx + e->px, e->fy + e->py, 0.f);
	glColor3f(0.f, 0.0f, 0.5f);
	glVertex3f(e->fx + e->sx - e->px, e->fy + e->py, 0.f);
	glColor3f(0.f, 0.0f, 0.5f * 10.f / 6.f);
	glVertex3f(e->fx + e->sx - e->px, e->fy + e->sy - e->py, 0.f);
}

void	ft_draw_brick_4(t_env *e)
{
	glColor3f(5.f * 6.f / 100.f, 0.f, 0.f);
	glVertex3f(e->fx + e->px, e->fy + e->sy - e->py, 0.f);
	glColor3f(5.f, 0.f, 0.f);
	glVertex3f(e->fx + e->px, e->fy + e->py, 0.f);
	glColor3f(5.f, 0.f, 0.f);
	glVertex3f(e->fx + e->sx - e->px, e->fy + e->py, 0.f);
	glColor3f(5.f * 10.f / 6.f, 0.f, 0.f);
	glVertex3f(e->fx + e->sx - e->px, e->fy + e->sy - e->py, 0.f);
}
