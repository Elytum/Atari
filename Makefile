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
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./includes -O3
#--------------Name-------------------------#
NAME = arkanoid

#--------------Sources----------------------#
FILES =	main.c				\
		parsing/gnl.c		\
		parsing/parsing.c	\
		tools/singletons.c	\
		tools/math.c		\
		drawings/draw_items.c \
		drawings/draw_bricks.c \
		drawings/draw_brick_1.c \
		drawings/draw_brick_2.c \
		drawings/draw_sphere.c \
		collisions/collisions.c \
		collisions/bricks_col.c \
		sound/play_sounds.c		\
		events/events.c

OBJECT = $(patsubst %.c,%.o,$(FILES))
OBJ = $(addprefix $(BASEDIR)/, $(OBJECT))
BASEDIR = srcs

CURRENT_DIR = $(shell pwd)/$(NAME)
#--------------Actions----------------------#

all:$(NAME)

$(NAME): $(OBJ)
	git submodule init
	git submodule update
#	cd ./glfw;ccmake -DCMAKE_INSTALL_PREFIX:PATH=~/glfw .;make install
	make -C libft
	@$(CC) -o $(NAME) libft/libft.a $(OBJ) -L ~/glfw/lib -lglfw -framework OpenGL

%.o: %.c
	$(CC) -o $@ -c $(CFLAGS) -I ~/glfw/include -I ./includes -I ./libft -I ./glfw/deps/ $<
	@git submodule update

clean:
		rm -Rf $(OBJ)

fclean: clean
		rm -Rf $(NAME)
		rm -rf glfw
		rm -rf libft/libft.a

re: fclean all

.PHONY: all, fclean, clean, re 

