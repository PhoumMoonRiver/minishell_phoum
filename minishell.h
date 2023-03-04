/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:16:53 by njerasea          #+#    #+#             */
/*   Updated: 2023/03/04 18:51:38 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/history.h>
# include <readline/readline.h>

typedef struct t_bigstruct
{
	char **my_env;
	char *cmd_prompt;
	struct t_command *list_cmd;
}	t_bst;

typedef struct t_command
{
	int cmd_id;
	struct t_bigstruct *big_struct;
	struct t_command *next;
}	t_cmd;

/*libft*/
int	ft_strncmp(char *src, char *des, int num);

/*process*/
void ft_process(t_bst *bst);

/*lexer*/
int set_env_begin(int ac, char **av, char **env, t_bst *bst); //keep env

#endif
