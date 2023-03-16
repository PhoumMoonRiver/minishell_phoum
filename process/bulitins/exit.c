/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:19:41 by njerasea          #+#    #+#             */
/*   Updated: 2023/03/10 15:26:12 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_free_myenv(t_bst *bst)
{
	int	i;

	i = 0;
	while (bst->my_env[i])
	{
		free(bst->my_env[i]);
		i++;
	}
}

void	bulitins_exit(t_bst *bst)
{
	ft_free_myenv(bst);
}
