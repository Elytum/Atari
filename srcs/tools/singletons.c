/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <atari.h>

t_env		*get_singleton(t_env *e)
{
	static t_env	*save = 0x00000000;

	if (e)
		save = e;
	return (save);
}

GLFWwindow	*get_window(GLFWwindow *window)
{
	static GLFWwindow	*save = 0x00000000;

	if (window)
		save = window;
	return (save);
}

