/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <atari.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <signal.h>

static void		error_callback(int error, const char *description)
{
	write(2, description, ft_strlen(description));
	(void)error;
}

static void		key_callback(GLFWwindow *window, int key,
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

void			ft_check_lost(t_env *e, GLFWwindow *window)
{
	if (e->posbally <= -1)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void			refresh_frame(GLFWwindow *window)
{
	double		ratio;
	int			height;
	int			width;

	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (double)height;
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	ft_draw_background();
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int				main(void)
{
	int			i;
	t_env		*e;
	GLFWwindow	*window;

	i = -1;
	e = (t_env *)malloc(sizeof(t_env));
	e->map = NULL;
	get_map(e, i, "./level/0.lvl");
	print_map(e);
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	window = glfwCreateWindow(1000, 1000, "Arkanoid", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(0);
	e->transpos = 0;
	glfwSetKeyCallback(window, key_callback);
	get_singleton(e);
	e->posballx = .95;
	e->posbally = -.2;
	e->vecballx = -0.002f;
	e->vecbally = 0.002f;
	e->r = 0.01;
	e->speed = 0.9;
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
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
