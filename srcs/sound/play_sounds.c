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
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/errno.h>
#include <time.h>
#include <fcntl.h>
	
void	ft_playsound(char sound)
{
	static char *block_sounds[5] = {"travail_termine.mp3",
	"travail_termine.mp3", "travail_termine.mp3", "peon_travail.mp3",
	"peon_travail.mp3"};
	static char *buff[3] = {"/usr/bin/afplay", NULL, NULL};
	static int cpid_saved = 0;
	int		r;

	if (sound == BLOCK_DESTRUCT)
	{
		if (cpid_saved > 0)
			kill (cpid_saved, 9);
		srand(time(NULL));
		r = rand() % 5;
		buff[1] = block_sounds[r];
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