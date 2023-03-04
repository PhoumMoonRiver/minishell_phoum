/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_begin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:52:17 by njerasea          #+#    #+#             */
/*   Updated: 2023/03/04 17:28:56 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
		bst->my_env[i] = env[i];
		i++;
	}
	bst->my_env[i] = NULL;
	return (0);
}
