# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2014/12/13 12:55:35 by achazal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------Compilateur------------------#
CC		=	gcc
#--------------Name-------------------------#
NAME	=	arkanoid
MYPATH	=	$(HOME)
#--------------Sources----------------------#
FILES	=	main.c					\
			parsing/gnl.c			\
			parsing/parsing.c		\
			tools/singletons.c		\
			tools/math.c			\
			drawings/draw_items.c	\
			drawings/draw_bricks.c	\
			drawings/draw_brick_1.c	\
			drawings/draw_brick_2.c	\
			drawings/draw_sphere.c	\
			collisions/collisions.c	\
			collisions/bricks_col.c	\
			sound/play_sounds.c		\
			events/events.c			\
			events/events2.c
INC		=	-I./glfw/include/ -I./libft/ -I./includes
GLFWLIB	=	glfw/src/libglfw3.a
CCFLAGS	=	-Wall -Wextra -Werror -g
LDFLAGS	=	-L./glfw/src -lglfw3 -framework glut -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo -L./libft/ -lft

SRCS	=	$(addprefix srcs/, $(FILES))
OBJS	=	$(SRCS:.c=.o)

#--------------Actions----------------------#

all: $(GLFWLIB) $(NAME)

$(GLFWLIB):
	git submodule update --init
	cmake -B./glfw -H./glfw
	make -C ./glfw

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CCFLAGS) $(LDFLAGS) $(INC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c  $(INC) $< -o $@
	
clean:
	@make clean -C libft
	rm -f $(OBJS)
	
fclean:	clean
	@make fclean -C libft
	rm -f $(NAME)

re: fclean all

