/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bricks_col.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARI_H
# define ATARI_H
# define BUFF_SIZE 128
# define BLOCK_DESTRUCT 1
# define M_PI 3.14159265358979323846
# include <GLFW/glfw3.h>

typedef struct		s_save
{
	int				fd;
	char			*save;
	struct s_save	*next;
}					t_save;

typedef struct		s_draw_b
{
	int				fd;
	char			*save;
	struct s_save	*next;
}					t_draw_b;

typedef struct		s_env
{
	char			**map;
	int				transpos;
	double			posballx;
	double			posbally;
	double			pasballx;
	double			pasbally;
	double			vecballx;
	double			vecbally;
	double			speed;
	double			r;
	double			fx;
	double			sx;
	double			px;
	double			fy;
	double			sy;
	double			py;
	char			alive;
	char			lives;
	char			launched;
	int				blocks;
	char			id;
}					t_env;

int					gnl(int const fd, char **line);
void				print_map(t_env *e);
void				get_map(t_env *e);
t_env				*get_singleton(t_env *e);
GLFWwindow			*get_window(GLFWwindow *window);

/*
**Math functions
*/
double				ft_abs(const double v);
double				ft_sqrt(const double n);
double				ft_sin(const double x);
double				ft_cos(double x);

/*
**Draw functions
*/
void				ft_draw_pad(t_env *e);
void				ft_draw_background(void);
void				ft_draw_bricks(t_env *e);
void				ft_draw_brick_2(t_env *e);
void				ft_draw_brick_3(t_env *e);
void				ft_draw_brick_4(t_env *e);
void				ft_draw_brick_5(t_env *e);
void				ft_draw_brick__1(t_env *e);
void				ft_draw_brick__2(t_env *e);
void				ft_draw_brick__3(t_env *e);

/*
**Check collisions
*/
void				ft_check_collision_map(t_env *e);
void				ft_check_collision_barre(t_env *e);
void				ft_check_collision(t_env *e);
void				ft_draw_sphere(t_env *e);

/*
**Sound
*/
void				ft_playsound(char sound);

/*
**Events
*/
void				refresh_frame(GLFWwindow *window);
void				ft_check_lost(t_env *e);
void				error_callback(int error, const char *description);
void				key_callback(GLFWwindow *window, int key, int scancode,
								int action, int mods);
void				ft_init(t_env *e, GLFWwindow *window);
void				ft_game_loop(t_env *e, GLFWwindow *window);
void				ft_end(void);

#endif
