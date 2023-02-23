/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_begin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:52:17 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/23 18:04:42 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void set_env_begin(int ac, char **av, char **env, t_bst *bst)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	(void)ac;
	(void)av;
	while (env[i])
		i++;
	printf("i ==> [%d]\n", i);
	(void)bst;
	exit(0);
}
