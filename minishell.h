/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:16:53 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/23 18:03:17 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct t_command
{
	int cmd_id;
	struct t_enviroment *bigstruct;
	struct t_command *next;
}	t_cmd;

typedef struct t_bigstruct
{
	char **my_env;
	struct t_command *cmd;
}	t_bst;

/*lexer*/
void set_env_begin(int ac, char **av, char **env, t_bst *bst);

#endif
