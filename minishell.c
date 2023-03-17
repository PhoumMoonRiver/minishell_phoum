/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:43:21 by njerasea          #+#    #+#             */
/*   Updated: 2023/03/17 20:12:52 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	input ==> [ls -la]
*/

int	main(int ac, char **av, char **env)
{

	(void)ac;
	(void)av;
	(void)env;

	int	i;
	t_bst bst;

	i = 0;
	bst.executor = malloc(sizeof(t_executor));
	bst.executor->cmd = (char **)malloc(sizeof(char *) * 3);
	bst.executor->cmd[0] = "ls";
	bst.executor->cmd[1] = "-la";
	while (bst.executor->cmd[i])
	{
		printf("This is test --> [%s]\n", bst.executor->cmd[i]);
		i++;
	}
}
