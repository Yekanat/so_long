# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: athekkan <athekkan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 18:37:07 by athekkan          #+#    #+#              #
#    Updated: 2023/11/21 20:55:17 by athekkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

CC				=	gcc

RM				=	rm -f

HEADER			=	./so_long.h

LIBFT_PATH		=	./libft

LIBFT			=	$(LIBFT_PATH)

MLX_PATH		=	./mlx_linux

SRCS	=	main.c \
      draw_map.c \
      so_long.c  \
      check_map.c \
	  path_finder.c \
	  check_map_init.c \
      player.c

OBJS			= 	$(SRCS:.c=.o)

MLX				=	./libmlx.dylib


FLGS			=	-Wall -Wextra -Werror -g

%.o: %.c
	$(CC) ${FLGS} -Imlx -c $< -o $@

all:			$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
				make -C $(LIBFT_PATH)
				make -C $(MLX_PATH)
			$(CC) $(OBJS) $(LIBFT)/libft.a -L./mlx_linux -lmlx_Linux -L/usr/lib -I./mlx_linux -lXext -lX11 -lm -lz -o $(NAME)




clean:
				${RM} ${OBJS}
				make clean -C ${LIBFT_PATH}



fclean:			clean
				make fclean -C $(LIBFT_PATH)
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean re
