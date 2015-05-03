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

void			ft_check_lost(t_env *e)
{
	if (e->posbally <= -1)
		e->alive = 0;
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
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (-1);
	e->map = NULL;
	get_map(e, i, "./level/0.lvl");
	print_map(e);
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	if (!(window = glfwCreateWindow(1000, 1000, "Arkanoid", NULL, NULL)))
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	ft_init(e, window);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(0);
	glfwSetKeyCallback(window, key_callback);
	ft_game_loop(e, window);
	ft_end();
	return (0);
}
