# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sforster <sforster@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 11:38:14 by sforster          #+#    #+#              #
#    Updated: 2023/11/22 12:09:56 by sforster         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c	ft_print_c.c	ft_print_s.c	ft_print_d.c\
		ft_print_x.c	ft_print_i.c	ft_print_u.c	ft_print_xup.c\
		ft_print_p.c
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

OBJ := $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
				ar	-rcs $(NAME) $(OBJ)
				ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re: fclean 	all

.PHONY:		all re clean fclean bin