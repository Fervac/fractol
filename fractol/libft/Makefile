# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abechet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 17:04:09 by abechet           #+#    #+#              #
#    Updated: 2018/12/21 11:48:49 by abechet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Werror -Wextra -Wall
SRCS =	ft_putchar.c\
		ft_putstr.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_memalloc.c\
		ft_memset.c\
		ft_memdel.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strdup.c\
		ft_strcpy.c\
		ft_strsub.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strstr.c\
		ft_strlen.c\
		ft_strlcat.c\
		ft_atoi.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_bzero.c\
		ft_isupper.c\
		ft_islower.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalpha.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_isspace.c\
		ft_strnew.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_strchr.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_strrchr.c\
		ft_strncpy.c\
		ft_strcat.c\
		ft_memcmp.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_countwords.c\
		ft_strsplit.c\
		ft_strncat.c\
		ft_strnstr.c\
		ft_stpcpy.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_strndup.c\
		ft_isxdigit.c\
		ft_strcspn.c\
		ft_strjoinfree.c\
		get_next_line.c

OBJ = $(SRCS:.c=.o)
HEADER = libft.h
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar r $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $< -I $(HEADER)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all
