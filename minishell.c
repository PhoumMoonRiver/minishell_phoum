/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:16:41 by njerasea          #+#    #+#             */
/*   Updated: 2023/03/10 15:32:23 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_bst bst;

	if (set_env_begin(ac, av, env, &bst) == 1)
		return (0);
	while (1)
	{
		bst.cmd_prompt = readline("\e[0;32mminishell -> \033[0m");
		if (!bst.cmd_prompt)
		{
			printf("--> EXIT <--\n");
			bulitins_exit(bst);
			exit(0);
		}
		else
		{
			if (bst.cmd_prompt[0] == '\0')
				free(bst.cmd_prompt);
			else
				ft_process(&bst);
		}
	}
	return (0);
}
