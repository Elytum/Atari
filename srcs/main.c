#include "atari.h"
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
    (void)error;
}

t_env		*batardarthurtg(t_env *e)
{
	static t_env	*l = NULL;

	if (e)
		l = e;
	return (l);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	t_env	*e;

	e = batardarthurtg(NULL);
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    else if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
    	if (e->transpos < 100 - 20)
	    	e->transpos += 3;
    }
    else if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
    	if (e->transpos > -100 + 20)
        	e->transpos -= 3;
    }
    (void)scancode;
    (void)mods;
}

void	ft_check_collision(t_env *e)
{
	int		i;
	int		j;
	float	fx;
	float	sx;
	float	px;
	float	fy;
	float	sy;
	float	py;

	i = 0;
	sx = 2 / (float)ft_strlen(e->map[i]);
	px = sx / 20;
	sy = 0;

	while (e->map[(int)sy])
		sy++;
	sy = (2 / (sy - 1)) / 2;
	py = sy / 20;
	while (e->map[i])
	{
		j = 0;
		while (e->map[i][j])
		{
			if (e->map[i][j] != 1)
			{
				fx = -1 + j * sx;
				fy = 1 - (i + 1) * sy;
				if (e->posballx >= (fx + px) && e->posballx <= (fx + sx - px) && e->posbally <= (fy + sy - py) && e->posbally >= (fy + py))
					e->map[i][j]--;
			}
		    j++;	
		}
		i++;
	}
}

void	ft_affiche_les_briques(t_env *e)
{
	int		i;
	int		j;
	float	fx;
	float	sx;
	float	px;
	float	fy;
	float	sy;
	float	py;

	i = 0;
	sx = 2 / (float)ft_strlen(e->map[i]);
	px = sx / 20;
	sy = 0;
	while (e->map[(int)sy])
		sy++;
	sy = (2 / (sy - 1)) / 2;
	py = sy / 20;
	while (e->map[i])
	{
		j = 0;
		while (e->map[i][j])
		{
			if (e->map[i][j] != 1)
			{
				glBegin(GL_QUADS);
				fx = -1 + j * sx;
				fy = 1 - (i + 1) * sy;
				if (e->map[i][j] == 2)
				{
					glColor3f(0.f, 0.5f * 6.f/10.f, 0.0f); // BAS GAUCHE
					glVertex3f(fx + px, fy + sy - py, 0.f);
					glColor3f(0.f, 0.5f, 0.0f); // HAUT GAUCHE
					glVertex3f(fx + px, fy + py, 0.f);
					glColor3f(0.f, 0.5f, 0.0f); // HAUT DROITE
					glVertex3f(fx + sx - px, fy + py, 0.f);
					glColor3f(0.f, 0.5f * 10.f/6.f, 0.0f); // BAS DROITE
					glVertex3f(fx + sx - px, fy + sy - py, 0.f);
				}
				else if (e->map[i][j] == 3)
				{
					glColor3f(0.f, 0.0f, 0.5f * 6.f/10.f);
					glVertex3f(fx + px, fy + sy - py, 0.f);
					glColor3f(0.f, 0.0f, 0.5f);
					glVertex3f(fx + px, fy + py, 0.f);
					glColor3f(0.f, 0.0f, 0.5f);
					glVertex3f(fx + sx - px, fy + py, 0.f);
					glColor3f(0.f, 0.0f, 0.5f * 10.f/6.f);
					glVertex3f(fx + sx - px, fy + sy - py, 0.f);
				}
				else if (e->map[i][j] == 4)
				{
					glColor3f(5.f * 6.f/100.f, 0.f, 0.f);
					glVertex3f(fx + px, fy + sy - py, 0.f);
					glColor3f(5.f, 0.f, 0.f);
					glVertex3f(fx + px, fy + py, 0.f);
					glColor3f(5.f, 0.f, 0.f);
					glVertex3f(fx + sx - px, fy + py, 0.f);
					glColor3f(5.f * 10.f/6.f, 0.f, 0.f);
					glVertex3f(fx + sx - px, fy + sy - py, 0.f);
				}
				else if (e->map[i][j] == 5)
				{
					glColor3f(0.2f * 6.f/10.f, 0.2f * 6.f/10.f, 0.2f * 6.f/10.f);
					glVertex3f(fx + px, fy + sy - py, 0.f);
					glColor3f(0.2f, 0.2f, 0.2f);
					glVertex3f(fx + px, fy + py, 0.f);
					glColor3f(0.2f, 0.2f, 0.2f);
					glVertex3f(fx + sx - px, fy + py, 0.f);
					glColor3f(0.2f * 10.f/6.f, 0.2f * 10.f/6.f, 0.2f * 10.f/6.f);
					glVertex3f(fx + sx - px, fy + sy - py, 0.f);
				}
			}
		    glEnd();
		    j++;	
		}
		i++;
	}
}

void		aff_bare(t_env *e)
{
	glTranslatef((float) e->transpos * 0.01f, 0.f, 0.f);
	glBegin(GL_LINES);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(-0.2f, -0.99f, 0.f);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(0.2f, -0.99f, 0.f);
	glEnd();
}

void		refresh_frame()
{
	float ratio;
	int width, height;
	// glfwPollEvents();

	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float) height;

	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
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
	get_map(e, i, "./level/2.lvl");
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
	e->posballx = 0;
	e->posbally = -0.99;
    glfwSetKeyCallback(window, key_callback);
    batardarthurtg(e);


    while (!glfwWindowShouldClose(window))
    {
    	refresh_frame();
        ft_check_collision(e);
//     	e->posballx = 0;
//		e->posbally = -0.99;

		ft_affiche_les_briques(e);
       	aff_bare(e);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}