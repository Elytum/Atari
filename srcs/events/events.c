/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
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
	else if (key == GLFW_KEY_SPACE && (action == GLFW_PRESS ||
		action == GLFW_REPEAT))
	{
		if (!e->launched)
			e->launched = 1;
	}
	(void)scancode;
	(void)mods;
}

void			ft_launch(t_env *e, GLFWwindow *window)
{
	e->launched = 0;
	while (!e->launched && !glfwWindowShouldClose(window))
	{
		refresh_frame(window);
		ft_draw_sphere(e);
		ft_draw_bricks(e);
		ft_draw_pad(e);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void			ft_game_loop(t_env *e, GLFWwindow *window)
{
	e->lives = 3;
	while (e->lives > 0 && !glfwWindowShouldClose(window))
	{
		e->alive = 1;
		ft_init(e, window);
		ft_launch(e, window);
		while (e->blocks > 0 && e->alive > 0 &&
			!glfwWindowShouldClose(window))
		{
			refresh_frame(window);
			ft_draw_sphere(e);
			ft_draw_bricks(e);
			ft_draw_pad(e);
			ft_check_collision(e);
			ft_check_collision_map(e);
			ft_check_collision_barre(e);
			ft_check_lost(e);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		if (e->alive == 0)
			e->lives--;
	}
}
