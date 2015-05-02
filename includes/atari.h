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
}					t_env;

int					gnl(int const fd, char **line);
void				print_map(t_env *e);
void				get_map(t_env *e, int fd, char *file);
#endif