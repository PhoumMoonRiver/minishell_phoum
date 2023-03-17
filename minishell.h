

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:16:53 by njerasea          #+#    #+#             */
/*   Updated: 2023/03/16 17:35:22 by njerasea         ###   ########.fr       */
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
	struct t_process_lexer *lexer;
	struct t_command *list_cmd;
}	t_bst;

typedef struct t_process_lexer
{

	struct t_bigstruct *big_struct;
}	t_lexer

#endif
