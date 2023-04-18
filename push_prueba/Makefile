# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 16:42:14 by iortega-          #+#    #+#              #
#    Updated: 2023/04/10 16:42:14 by iortega-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	= error_manage.c \
			push_swap.c \
			push_utils.c \
			push_utils2.c \
			sort.c \
			additional_ft.c \
			lst_utils.c \
			sort_utils.c \
			free.c

OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): ${OBJS}
	gcc -o ${NAME} ${OBJS}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all