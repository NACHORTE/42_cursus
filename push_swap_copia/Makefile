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
			libft/ft_atoi.c \
			libft/ft_isdigit.c \
			libft/ft_lstadd_back.c \
			libft/ft_lastadd_front.c \
			libft/ft_lstlast.c \
			libft/ft_lstnew.c \
			libft/ft_lstsize.c \
			libft/ft_strlen.c

OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I./
	ar rc $(NAME) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all