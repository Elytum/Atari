#include "atari.h"

int		main(void)
{
	int		i;
	t_env	*e;

	i = -1;
	e = (t_env *)malloc(sizeof(t_env));
	e->map = NULL;
	get_map(e, i, "./level/1.lvl");
	print_map(e);
}