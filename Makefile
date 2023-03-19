# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njerasea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 17:14:37 by njerasea          #+#    #+#              #
#    Updated: 2023/03/19 16:07:50 by njerasea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = minishell.c\
		executor/executor.c\
		libft/ft_split.c\
		libft/ft_strncmp.c\
		libft/ft_strjoin.c\
		libft/ft_strlen.c\
		libft/ft_free2d.c\
		libft/ft_strdup.c\
		initialism/initialism_struct.c\
		debug/debug.c

CC = gcc -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

$(NAME):
	$(CC) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)
	$(RM) minishell.dSYM

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
