# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 20:17:24 by iortega-          #+#    #+#              #
#    Updated: 2023/08/09 12:32:27 by iortega-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC		= gcc

STANDARD_FLAGS	= -Wall -Wextra -Werror
MINILIBX_FLAGS	= -Lmlx -lmlx -Imlx -framework OpenGL -framework AppKit

SRCS			= image_manage.c \
				main.c \
				map_check.c \
				map_manage.c \
				mem_manage.c \
				movement.c \
				playable_map.c

GNL_SRCS		= ./get_next_line/get_next_line.c \
				./get_next_line/get_next_line_utils.c

OBJS			= $(SRCS:.c=.o)

GNL_OBJS		= get_next_line.o \
				get_next_line_utils.o

all:			$(NAME)

$(NAME): $(OBJS)
				$(CC) $(OBJS) $(GNL_OBJS) $(MINILIBX_FLAGS) -o $(NAME)

$(OBJS): $(SRCS)
				$(CC) $(STANDARD_FLAGS) -Imlx -c $(SRCS) $(GNL_SRCS)

clean:
				rm -rf $(OBJS) $(GNL_OBJS)

fclean:
				make clean
				rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re