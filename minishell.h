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

/* ==>   Libft   <== */
int		ft_strncmp(char *src, char *des, int num); //cmpstr
int		ft_strlen(char *str); //find len of str
char	*ft_strchr(const char *s, int c); //find c left to right
char	*ft_strtrim(char const *s1, char const *set); //trim str
char	*ft_substr(char const *s, unsigned int start, size_t len); //sub str

/* ==>  Process  <== */
void 	ft_process(t_bst *bst); //begin minishell process


/* ==>   Lexer   <== */
int 	set_env_begin(int ac, char **av, char **env, t_bst *bst); //keep env
void	lexer(t_bst *bst); //main of lexer


/* ==> Bulitins <== */
/*exit*/
void	bulitins_exit(t_bst *bst); //bulitins_exit
void	ft_free_myenv(t_bst *bst); //free_myenv

#endif
