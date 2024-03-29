/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:25:10 by njerasea          #+#    #+#             */
/*   Updated: 2023/03/16 17:43:30 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_process(t_bst *bst)
{
	add_history(bst->cmd_prompt);
	if (ft_strncmp(bst->cmd_prompt, "exit\0", 6) == 0)
	{
		printf("minishell exit");
		free(bst->cmd_prompt);
		bulitins_exit(bst);
		exit(0);
	}
	lexer(bst);
}
