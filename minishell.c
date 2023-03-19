/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:43:21 by njerasea          #+#    #+#             */
/*   Updated: 2023/03/19 16:54:06 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	input ==> [ls -la]
*/

int set_env_begin(int ac, char **av, char **env, t_bst *bst)
{
	int	i;

	i = 0;
	(void)ac;
	(void)av;
	while (env[i])
		i++;
	bst->my_env = (char **)malloc(sizeof(char **) * (i + 1));
	if (!bst->my_env)
		return (1);
	i = 0;
	while (env[i])
	{
		bst->my_env[i] = ft_strdup(env[i]);
		i++;
	}
	bst->my_env[i] = NULL;
	return (0);
}


int	main(int ac, char **av, char **env)
{
	int	i;
	t_bst	bst;

	i = 0;

	bst.executor = malloc(sizeof(t_executor));
	initialism_big_struct(&bst);
	bst.executor->cmd = (char **)malloc(sizeof(char *) * 3);
	bst.executor->cmd[0] = 	ft_strdup("cat");
	bst.executor->cmd[1] = ft_strdup("minishell.c");
	bst.executor->cmd[2] = NULL;
	if (set_env_begin(ac, av, env, &bst) == 1)
		return (0);
	executor(&bst);

	ft_free2d(bst.executor->cmd);
	ft_free2d(bst.my_env);
	free(bst.executor->execute_path);
	free(bst.executor);
}
