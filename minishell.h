/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:35:08 by njerasea          #+#    #+#             */
/*   Updated: 2023/03/17 20:10:19 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>


typedef struct s_process_expander
{
	char							**cmd;
	struct s_bigstruct 				*big_struct;
	struct s_process_executor 		*executor;
	struct s_process_expander 		*next;
}	t_expander;

typedef struct s_process_executor
{
	pid_t							pid;
	char 							**cmd;
	char 							*execute_path;
	int								fd_pipe[2];
	int								fd_in;
	int								fd_out;
	struct s_bigstruct 				*big_struct;
	struct s_process_expander 		*expander;
	struct s_process_executor 		*next;
}	t_executor;

typedef struct s_bigstruct
{
	int								round_pipe;
	t_expander						*expander;
	t_executor						*executor;
}	t_bst;

#endif
