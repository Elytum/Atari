/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <atari.h>
#include <unistd.h>
#include <stdlib.h>

void			ft_end(void)
{
	glfwDestroyWindow(get_window(NULL));
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

void			ft_init(t_env *e, GLFWwindow *window)
{
	get_window(window);
	get_singleton(e);
	e->transpos = 0;
	e->posballx = e->transpos * 0.01f;
	e->posbally = -0.98;
	e->vecballx = -0.2f;
	e->vecbally = 0.2f;
	e->r = 0.01;
	e->speed = 1;
}
