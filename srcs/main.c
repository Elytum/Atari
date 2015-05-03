#include "atari.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/errno.h>
#include <time.h>

#define BLOCK_DESTRUCT 1
char	*BLOCK_SOUNDS[5] = {"travail_termine.mp3", "travail_termine.mp3",
			"travail_termine.mp3", "peon_travail.mp3", "peon_travail.mp3"};

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
    (void)error;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	t_env	*e;

	e = get_singleton(NULL);
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    else if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
    	if (e->transpos < 100 - 20)
	    	e->transpos += 10;
    }
    else if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
    	if (e->transpos > -100 + 20)
        	e->transpos -= 10;
    }
    (void)scancode;
    (void)mods;
}

void	ft_playsound(char sound)
{
	static char *buff[3] = {"/usr/bin/afplay", NULL, NULL};
	static int cpid_saved = 0;
	int		r;

	if (sound == BLOCK_DESTRUCT)
	{
		if (cpid_saved > 0)
			kill (cpid_saved, 9);
		srand(time(NULL));
		r = rand() % 5;
		buff[1] = BLOCK_SOUNDS[r];
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

// void	ft_playpermasound(char sound)
// {
// 	static char *buff[3] = {"/usr/bin/afplay", NULL, NULL};
// 	int		cpid;
// 	int		r;

// 	if (sound == BLOCK_DESTRUCT)
// 	{
// 		if (cpid_saved > 0)
// 			kill (cpid_saved, 9);
// 		srand(time(NULL));
// 		r = rand() % 5;
// 		if (r == 0)
// 			buff[1] = "travail_termine.mp3";
// 		else
// 			buff[1] = "peon_travail.mp3";
// 		cpid_saved = fork();
// 	}
// 	if (cpid_saved != -1)
// 	{
// 		if (cpid_saved == 0)
// 			execv(buff[0], buff);
// 		else
// 			waitpid(-1, NULL, O_NONBLOCK);
// 	}
// }


void	ft_check_collision(t_env *e)
{
	int		i;
	int		j;
	double	fx;
	double	sx;
	double	px;
	double	fy;
	double	sy;
	double	py;
	double	t;

	i = 0;
	sx = 2 / (double)ft_strlen(e->map[i]);
	px = sx / 42;
	sy = 0;

	while (e->map[(int)sy])
		sy++;
	sy = (2 / (sy - 1)) / 2;
	py = sy / 42;
	while (e->map[i])
	{
		j = 0;
		while (e->map[i][j])
		{
			if (e->map[i][j] != 1)
			{
				fx = -1 + j * sx;
				fy = 1 - (i + 1) * sy;
				if (e->pasballx < fx + px && e->posballx > fx + px) //LEFT
				{
					t = (((e->posbally - e->pasbally) / (e->posballx - e->pasballx)) * (fx + px - e->pasballx)) + e->pasbally;
					if (fy + py <= t && fy + sy - py >= t)
					{
						e->posbally = t;
						e->posballx = fx + px;
						e->vecballx = -e->vecballx;
						if (e->map[i][j] > 1)
							e->map[i][j]--;
						e->speed *= 1.00005;
						ft_playsound(BLOCK_DESTRUCT);
					}
				}
				if (e->pasballx > fx + sx - px && e->posballx < fx + sx - px) //RIGHT
				{
					t = (((e->posbally - e->pasbally) / (e->posballx - e->pasballx)) * (fx + sx - px - e->pasballx)) + e->pasbally;
					if (fy + py <= t && fy + sy - py >= t)
					{
						e->posbally = t;
						e->posballx = fx + sx - px;
						e->vecballx = -e->vecballx;
						if (e->map[i][j] > 1)
							e->map[i][j]--;
						e->speed *= 1.00005;
						ft_playsound(BLOCK_DESTRUCT);
					}
				}
				if (e->pasbally < fy + py && e->posbally > fy + py) //DOWN
				{
					t = (((e->posballx - e->pasballx) / (e->posbally - e->pasbally)) * (fy + py - e->pasbally)) + e->pasballx;
					if (t >= fx + px && fx + sx - px >= t)
					{
						e->posballx = t;
						e->posbally = fy + py;
						e->vecbally = -e->vecbally;
						if (e->map[i][j] > 1)
							e->map[i][j]--;
						e->speed *= 1.00005;
						ft_playsound(BLOCK_DESTRUCT);
					}
				}
				if (e->pasbally > fy + sy - py && e->posbally < fy + sy - py) //UP
				{
					t = (((e->posballx - e->pasballx) / (e->posbally - e->pasbally)) * (fy + sy - py - e->pasbally)) + e->pasballx;
					if (fx + px <= t && fx + sx - px >= t)
					{
						e->posballx = t;
						e->posbally = fy + sy - py;
						e->vecbally = -e->vecbally;
						if (e->map[i][j] > 1)
							e->map[i][j]--;
						e->speed *= 1.00005;
						ft_playsound(BLOCK_DESTRUCT);
					}
				}
			}
		    j++;	
		}
		i++;
	}
}


void	ft_check_lost(t_env *e, GLFWwindow* window)
{
	if (e->posbally <= -1)
		glfwSetWindowShouldClose(window, GL_TRUE);
}


void		aff_sphere(t_env *e)
{
	// double	x;
	// double	y;
	double	r;

	e->vecbally -= 0.0000005;
	if (e->vecbally < 0)
	{
		e->speed *= 1.001;
		e->vecbally -= 0.0000005;
	}
	else
	{
		e->speed /= 1.00099;
		e->vecballx *= 1.0000005;
	}
	r = sqrt(e->vecballx * e->vecballx + e->vecbally * e->vecbally);
	e->vecballx = e->vecballx / r;
	e->vecbally = e->vecbally / r;
	e->pasballx = e->posballx;
	e->pasbally = e->posbally;
	e->posballx	+= e->vecballx / 500 * e->speed;
	e->posbally += e->vecbally / 500 * e->speed;
	glPushMatrix();
	glTranslatef((double) e->posballx * 1.0, e->posbally * 1.0, 0.f);



	double	slices = 20;
	glBegin(GL_TRIANGLES);
	const double delta_eta = M_PI / slices;

	// Outer (eta) Loop: Iterate over longitude (north-to-south).
	// Inner (theta) Loop: Iterate over latitude (east-to-west)
	glColor3f(1.f, 0.f, 0.f);
	for ( double eta0 = 0; eta0 < M_PI - 0.0001 - delta_eta; eta0 += delta_eta )
    {
      const double eta1 = eta0 + delta_eta;
      const double  y0 = cos(eta0),        y1 = cos(eta1);
      const double slice_r0 = sin(eta0),  slice_r1 = sin(eta1);
      const double delta_theta = delta_eta * slice_r1;

      for ( double theta = 0; theta < 2 * M_PI; theta += delta_theta )
        {
          const double theta1 = theta + delta_theta;

          /// Triangle 1

          // Vertex 1
          glNormal3f( slice_r1 * cos(theta), y1, slice_r1 * sin(theta) );
          glVertex3f( slice_r1 * cos(theta) / (1 / e->r), y1/ (1 / e->r), slice_r1 * sin(theta) / (1 / e->r));

          // Vertex 2
          glNormal3f( slice_r0 * cos(theta), y0, slice_r0 * sin(theta) );
          glVertex3f( slice_r0 * cos(theta) / (1 / e->r), y0/ (1 / e->r), slice_r0 * sin(theta) / (1 / e->r));

          // Vertex 3      
          glNormal3f( slice_r1 * cos(theta1), y1, slice_r1 * sin(theta1) );
          glVertex3f( slice_r1 * cos(theta1) / (1 / e->r), y1/ (1 / e->r), slice_r1 * sin(theta1)/ (1 / e->r) );

          /// Triangle 2

          // Vertex 3      
          glNormal3f( slice_r1 * cos(theta1), y1, slice_r1 * sin(theta1) );
          glVertex3f( slice_r1 * cos(theta1) / (1 / e->r), y1/ (1 / e->r), slice_r1 * sin(theta1)/ (1 / e->r) );

          // Vertex 2
          glNormal3f( slice_r0 * cos(theta), y0, slice_r0 * sin(theta) );
          glVertex3f( slice_r0 * cos(theta) / (1 / e->r), y0/ (1 / e->r), slice_r0 * sin(theta) / (1 / e->r));

          // Vertex 4
          glNormal3f( slice_r0 * cos(theta1), y0, slice_r0 * sin(theta1) );
          glVertex3f( slice_r0 * cos(theta1) / (1 / e->r), y0/ (1 / e->r), slice_r0 * sin(theta1)/ (1 / e->r) );

        }
    }
	glEnd();
	glPopMatrix();
}


void		refresh_frame(GLFWwindow* window)
{
	double 	ratio;
	int		height;
	int		width;

	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (double) height;

	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	ft_draw_background();
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int		main(void)
{
	int		i;
	t_env	*e;

	i = -1;
	e = (t_env *)malloc(sizeof(t_env));
	e->map = NULL;
	get_map(e, i, "./level/0.lvl");
	print_map(e);
	GLFWwindow* window;
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
	e->vecballx	= -0.002f;
	e->vecbally = 0.002f;
	e->r = 0.01;
	e->speed = 0.9;
    while (!glfwWindowShouldClose(window))
    {
    	refresh_frame(window); //
        ft_check_collision(e); //
		ft_check_collision_map(e); //
		ft_check_collision_barre(e); //
		ft_check_lost(e, window);
        aff_sphere(e); //
		ft_draw_bricks(e); //
       	aff_bare(e); //
        glfwSwapBuffers(window); //
        glfwPollEvents(); //
        //usleep(20000);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}