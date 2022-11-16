# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 15:24:25 by jtsizik           #+#    #+#              #
#    Updated: 2022/11/16 10:56:47 by jtsizik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

OBJS = 	obj/so_long.o \
		obj/ft_printf.o \
		obj/ft_hex.o \
		obj/ft_printf_utils.o \
		obj/ft_uint.o \
		obj/ft_itoa.o \
		obj/ft_calloc.o \
		obj/ft_bzero.o \
		obj/ft_split.o \
		obj/ft_strjoin.o \
		obj/ft_strncmp.o \
		obj/ft_strrchr.o \
		obj/ft_isascii.o \
		obj/ft_putstr_fd.o \
		obj/ft_strlen.o \
		obj/check_map.o \
		obj/check_valid_path.o \
		obj/close_game.o \
		obj/init_map.o \
		obj/movement.o \
		obj/read_map.o \
		obj/render_map.o

obj/%.o: %.c
	cc -c -Wall -Wextra -Werror $< -Imlx -o $@ -I so_long.h

obj/%.o: libft/%.c
	cc -c -Wall -Wextra -Werror $< -Imlx -o $@ -I libft/libft.h

obj/%.o: printf/%.c
	cc -c -Wall -Wextra -Werror $< -Imlx -o $@ -I printf/ft_printf.h

$(NAME): $(OBJS)
	cc -Wall -Wextra -Werror $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all