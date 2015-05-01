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
CFLAGS = -Wall -Werror -Wextra -I./includes -g -O3
#--------------Name-------------------------#
NAME = atari

#--------------Sources----------------------#
FILES =	main.c		\
		gnl.c		\
		parsing.c

OBJECT = $(patsubst %.c,%.o,$(FILES))
OBJ = $(addprefix $(BASEDIR)/, $(OBJECT))
BASEDIR = srcs

CURRENT_DIR = $(shell pwd)/$(NAME)
#--------------Actions----------------------#

all:$(NAME)

$(NAME): $(OBJ)
	git submodule init
	git submodule update
	make -C libft
	@$(CC) -o $(NAME) libft/libft.a $(OBJ) -L /usr/lib -ltermcap

%.o: %.c
	$(CC) -o $@ -c $(CFLAGS) $<
	@git submodule update

clean:
		rm -Rf $(OBJ)

fclean: clean
		rm -Rf $(NAME)
		rm -rf glfw
		rm -rf libft/libft.a

re: fclean all

.PHONY: all, fclean, clean, re 

