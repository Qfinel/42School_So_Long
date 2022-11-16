# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 18:35:42 by jtsizik           #+#    #+#              #
#    Updated: 2022/10/29 17:47:15 by jtsizik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	libft/ft_itoa.c \
		ft_printf_utils.c \
		ft_hex.c \
		ft_uint.c \
		ft_printf.c

OBJ =	ft_itoa.o \
		ft_printf_utils.o \
		ft_hex.o \
		ft_uint.o \
		ft_printf.o

$(NAME):
	cc -c -Wall -Wextra -Werror $(SRCS) -I ft_printf.h libft/libft.h
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all