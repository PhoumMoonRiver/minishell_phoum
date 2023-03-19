/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialism_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:19:34 by njerasea          #+#    #+#             */
/*   Updated: 2023/03/19 15:47:49 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	initialism_executor(t_bst *bst)
{
	bst->executor->fd_in = 0;
	bst->executor->fd_out = 0;
	bst->executor->cmd = NULL;
	bst->executor->execute_path = NULL;
	bst->executor->next = NULL;
}

void	initialism_big_struct(t_bst *bst)
{
	bst->round_pipe	 = 0;
	bst->my_env = NULL;
	initialism_executor(bst);
}
