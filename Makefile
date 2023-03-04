# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njerasea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 17:14:37 by njerasea          #+#    #+#              #
#    Updated: 2023/03/04 16:24:57 by njerasea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

READLINE_DIR = /usr/local/opt/readline/

SRCS = minishell.c\
		lexer/set_env_begin.c
#expander/quote.c

CC = gcc -Wall -Wextra -Werror

READLINE_F = -lreadline -I$(READLINE_DIR)include/ -L$(READLINE_DIR)lib/

RM = rm -rf

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(READLINE_F)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re