#ifndef ATARI_H
#define ATARI_H
# define BUFF_SIZE 128

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_save
{
	int				fd;
	char			*save;
	struct s_save	*next;
}					t_save;

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
}					t_env;

int					gnl(int const fd, char **line);
void				print_map(t_env *e);
void				get_map(t_env *e, int fd, char *file);
t_env				*get_singleton(t_env *e);

/*
Math functions
*/
double				ft_abs(double v);

/*
Draw functions
*/
void				aff_bare(t_env *e);
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
Check collisions
*/
void				ft_check_collision_map(t_env *e);
void				ft_check_collision_barre(t_env *e);
#endif