# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echouvet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 14:37:04 by echouvet          #+#    #+#              #
#    Updated: 2018/01/16 17:24:05 by tgoldber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
INCLUDES = fractol.h

LIB = ./libft
LIBPATH = libft/libft.a

SRC = main.c \
parser.c \
mandelbrot.c \
zoom_iteration.c \
julia.c \
basics.c \
burningship.c

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
EXT = -lmlx -framework OpenGL -framework Appkit

all: $(NAME)
	
$(NAME): $(OBJ)
	@make -C $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBPATH) $(EXT)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIB)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIB)

norme:
	norminette $(SRC) $(INCLUDES)

normeerrors:
	norminette $(SRC) $(INCLUDES) libft/* | grep -b1 Error

debug:
	$(CC) $(CFLAGS) -g3 -fsanitize=address -o $(NAME) $(OBJ) $(LIBPATH) $(EXT)

re: fclean all

.PHONY: all, re, clean, fclean, norme, normeerrors, debug, re
