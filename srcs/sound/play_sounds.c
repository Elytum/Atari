/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_sounds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <atari.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>

char			*ft_getblock_trach(int id)
{
	if (id == 0)
		return ("sounds/travail_termine.mp3");
	else if (id == 1)
		return ("sounds/travail_termine.mp3");
	else if (id == 2)
		return ("sounds/travail_termine.mp3");
	else if (id == 3)
		return ("sounds/peon_travail.mp3");
	else
		return ("sounds/peon_travail.mp3");
}

void			ft_playsound(char sound)
{
	int			r;
	static int	cpid_saved = 0;
	static char	*buff[3] = {"/usr/bin/afplay", NULL, NULL};

	if (sound == BLOCK_DESTRUCT)
	{
		if (cpid_saved > 0)
			kill (cpid_saved, 9);
		srand(time(NULL));
		r = rand() % 5;
		buff[1] = ft_getblock_trach(r);
		cpid_saved = fork();
	}
	if (cpid_saved != -1)
	{
		if (cpid_saved == 0)
			execv(buff[0], buff);
		else
			waitpid(-1, NULL, O_NONBLOCK);
	}
}
