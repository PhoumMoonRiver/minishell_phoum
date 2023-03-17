# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njerasea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 17:14:37 by njerasea          #+#    #+#              #
#    Updated: 2023/03/17 20:28:34 by njerasea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = minishell.c\
		executor/executor.c

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
