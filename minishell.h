/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:35:08 by njerasea          #+#    #+#             */
/*   Updated: 2023/03/20 18:15:18 by njerasea         ###   ########.fr       */
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
	int								fd_pipe[2];
	int								fd_in;
	int								fd_out;
	int								execute_sign;
	pid_t							pid;
	char 							**cmd;
	char 							*execute_path;
	struct s_bigstruct 				*big_struct;
	struct s_process_expander 		*expander;
	struct s_process_executor 		*next;
}	t_executor;

typedef struct s_bigstruct
{
	int								round_pipe;
	char							**my_env;
	t_expander						*expander;
	t_executor						*executor;
}	t_bst;

/* ==> EXECUTOR <== */
void	join_and_check_path(t_bst *bst, char **path_split, char *cmd);
void	executor(t_bst *bst);
void	split_path_form_env(t_bst *bst);

/* ==> LIBFT <== */
int	ft_strncmp(char *s1, char *s2, int n);
int	ft_strlen(char *str);
char	**ft_split(char *str, char del);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
void	ft_free2d(char **str);

/* ==> debug <== */
void	print_d_str(char **str);
void	print_str(char *str);
void	print_single_str(char *str);
void	print_list(t_bst *bst);

/* ==> initialism <== */
void	initialism_big_struct(t_bst *bst);
void	initialism_executor(t_bst *bst);

#endif
