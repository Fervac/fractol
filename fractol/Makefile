# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abechet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/09 16:57:49 by abechet           #+#    #+#              #
#    Updated: 2019/02/12 11:52:34 by abechet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Werror -Wextra -Wall
CCLIB = make -C libft/
SRC =	main.c			\
		get_input.c		\
		mandel.c		\
		julia.c			\
		burning.c		\
		helper.c		\
		set_exit.c

OBJ = $(SRC:.c=.o)
HEADER = fractol.h
NAME = fractol

all: $(NAME) Makefile

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -I $(HEADER) -L libft/ -lft -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CCLIB)
	$(CC) $(FLAGS) -o $@ -c $< -I $(HEADER)

clean:
	$(CCLIB) clean
	rm -f $(OBJ)

fclean: clean
	$(CCLIB) fclean
	rm -f $(NAME)

re: fclean all
