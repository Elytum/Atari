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
#include <libft.h>
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

void			ft_game_loop(t_env *e)
{
	GLFWwindow	*window;

	window = get_window(NULL);
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

void			ft_init_ball(t_env *e)
{
	e->posballx = .95;
	e->posbally = -.2;
	e->vecballx = -0.002f;
	e->vecbally = 0.002f;
	e->r = 0.01;
	e->speed = 1;
}

void			ft_end_game()
{
	glfwDestroyWindow(get_window(NULL));
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

int				main(void)
{
	int			i;
	t_env		*e;
	GLFWwindow	*window;

	i = -1;
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (-1);
	e->map = NULL;
	if (!(get_map(e, i, "./level/0.lvl")))
	{
		write(1, "Couldn't open file ./level/0.lvl or the map is invalid\n", 55);
		return (-1);
	}
	print_map(e);
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	if (!(window = glfwCreateWindow(1000, 1000, "Arkanoid", NULL, NULL)))
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	get_window(window);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(0);
	e->transpos = 0;
	glfwSetKeyCallback(window, key_callback);
	get_singleton(e);
	ft_init_ball(e);
	ft_game_loop(e);
	ft_end_game();
	return (0);
}
