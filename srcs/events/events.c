/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
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

void			error_callback(int error, const char *description)
{
	char		*ptr;

	ptr = (char *)description;
	while (*ptr)
		ptr++;
	write(2, description, ptr - description);
	(void)error;
}

void			key_callback(GLFWwindow *window, int key,
	int scancode, int action, int mods)
{
	t_env		*e;

	e = get_singleton(NULL);
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	else if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS ||
		action == GLFW_REPEAT))
	{
		if (e->transpos < 100 - 20)
			e->transpos += 10;
	}
	else if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS ||
		action == GLFW_REPEAT))
	{
		if (e->transpos > -100 + 20)
			e->transpos -= 10;
	}
	(void)scancode;
	(void)mods;
}

void			ft_game_loop(t_env *e, GLFWwindow *window)
{
	while (!glfwWindowShouldClose(window))
	{
		refresh_frame(window);
		ft_check_collision(e);
		ft_check_collision_map(e);
		ft_check_collision_barre(e);
		ft_check_lost(e, window);
		ft_draw_sphere(e);
		ft_draw_bricks(e);
		ft_draw_pad(e);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

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
	e->posballx = .95;
	e->posbally = -.2;
	e->vecballx = -0.002f;
	e->vecbally = 0.002f;
	e->r = 0.01;
	e->speed = 0.9;
}
