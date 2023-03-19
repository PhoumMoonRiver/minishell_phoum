/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:43:06 by njerasea          #+#    #+#             */
/*   Updated: 2023/03/19 16:11:07 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*join_and_check_path(t_bst *bst, char **path_split)
{
	int	i;
	char	*executor;
	char	*get_path;

	i = 0;
	while (path_split[i])
	{
		get_path = ft_strjoin(path_split[i], "/");
		executor = ft_strjoin(get_path, bst->executor->cmd[0]);
		free(get_path);
		if (access(executor, X_OK) == 0)
		{
			ft_free2d(path_split);
			return (executor);
		}
		free(executor);
		i++;
	}
	ft_free2d(path_split);
	return(bst->executor->cmd[0]);
}

void	split_path_form_env(t_bst *bst)
{
	int	i;
	char	**path_split;

	i = 0;
	while (ft_strncmp(bst->my_env[i], "PATH", 4) != 0)
		i++;
	path_split = ft_split(bst->my_env[i] + 5, ':');
	bst->executor->execute_path = join_and_check_path(bst, path_split);
}

void	executor(t_bst *bst)
{
	split_path_form_env(bst);
	execve(bst->executor->execute_path, bst->executor->cmd, bst->my_env);
}
