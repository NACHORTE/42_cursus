# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/18 15:06:00 by iortega-          #+#    #+#              #
#    Updated: 2023/08/11 12:23:32 by iortega-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC		= gcc

STANDARD_FLAGS	= -Wall -Wextra -Werror

SRCS			= ./src/pipex.c \
				./src/memory_handle.c \
				./src/child_handle.c \
				./src/command_handle.c

LIBFT_SRCS		= ./libft/ft_split.c \
				./libft/ft_strjoin.c \
				./libft/ft_strlen.c \
				./libft/ft_strncmp.c \
				./libft/ft_substr.c


OBJS			= pipex.o \
				memory_handle.o \
				child_handle.o \
				command_handle.o

LIBFT_OBJS		= ft_split.o \
				ft_strjoin.o \
				ft_strlen.o \
				ft_strncmp.o \
				ft_substr.o

all:			$(NAME)

$(NAME): $(OBJS)
				$(CC) $(OBJS) $(LIBFT_OBJS) $(STANDARD_FLAGS) -o $(NAME)

$(OBJS): $(SRCS)
				$(CC) $(STANDARD_FLAGS) -c $(SRCS) $(LIBFT_SRCS)

clean:
				rm -rf $(OBJS) $(LIBFT_OBJS)

fclean:
				make clean
				rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re