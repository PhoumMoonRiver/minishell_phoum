/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:43:21 by njerasea          #+#    #+#             */
/*   Updated: 2023/03/22 16:52:24 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	input ==> [ls -la] [|] [wc -l]
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
	t_bst	bst;
	t_executor *tmp;

/* ===> สร้าง NODE <=== */
	bst.executor = malloc(sizeof(t_executor));
	// initialism_big_struct(&bst);

	tmp = bst.executor;
	tmp->cmd = (char **)malloc(sizeof(char *) * 3);
	tmp->cmd[0] = ft_strdup("ls");
	tmp->cmd[1] = ft_strdup("-la");
	tmp->cmd[2] = NULL;
	tmp->next = malloc(sizeof(t_executor));
	tmp = tmp->next;

/* -> { | } <- */

	tmp->cmd = (char **)malloc(sizeof(char *) * 3);
	tmp->cmd[0] = ft_strdup("wc");
	tmp->cmd[1] = ft_strdup("-l");
	tmp->cmd[2] = NULL;
	tmp = tmp->next;
/* ===> สร้าง NODE <=== */

	if (set_env_begin(ac, av, env, &bst) == 1)
		return (0);

/* ข้อมูลที่พี่ฟ้าส่งมา */
	bst.round_pipe = 1;
/* ข้อมูลที่พี่ฟ้าส่งมา */

	executor(&bst);

	ft_free2d(bst.executor->cmd);
	ft_free2d(bst.my_env);
	free(bst.executor->execute_path);
	free(bst.executor);
}
