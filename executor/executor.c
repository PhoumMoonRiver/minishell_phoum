/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:43:06 by njerasea          #+#    #+#             */
/*   Updated: 2023/03/22 17:12:41 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	join_and_check_path(t_bst *bst, char **path_split, char *cmd)
// {
// 	int	i;
// 	char	*executor;
// 	char	*get_path;

// 	i = 0;
// 	while (path_split[i])
// 	{
// 		get_path = ft_strjoin(path_split[i], "/");
// 		executor = ft_strjoin(get_path, cmd);
// 		free(get_path);
// 		if (access(executor, X_OK) == 0)
// 		{
// 			bst->executor->execute_sign = 1;
// 			bst->executor->execute_path = executor;
// 			break ;
// 		}
// 		free(executor);
// 		i++;
// 	}
// }

// void	split_path_form_env(t_bst *bst)
// {
// 	int	i;
// 	int	j;
// 	char	**path_split;

// 	i = 0;
// 	j = 0;
// 	bst->executor->execute_sign = 0;
// 	while (ft_strncmp(bst->my_env[i], "PATH", 4) != 0)
// 		i++;
// 	path_split = ft_split(bst->my_env[i] + 5, ':');
// 	while (bst->executor->cmd[j] && bst->executor->execute_sign == 0)
// 	{
// 		join_and_check_path(bst, path_split, bst->executor->cmd[j]);
// 		j++;
// 	}
// 	ft_free2d(path_split);
// }

// void	executor(t_bst *bst)
// {
// 	split_path_form_env(bst);
// 	execve(bst->executor->execute_path, bst->executor->cmd, bst->my_env);
// }

void	join_and_check_path(t_bst *bst, char **path_split, char *cmd)
{
	int	i;
	char	*executor;
	char	*get_path;

	i = 0;
	while (path_split[i])
	{
		get_path = ft_strjoin(path_split[i], "/");
		executor = ft_strjoin(get_path, cmd);
		free(get_path);
		if (access(executor, X_OK) == 0)
		{
			bst->executor->execute_sign = 1;
			bst->executor->execute_path = executor;
			break ;
		}
		free(executor);
		i++;
	}
}

void	split_path_form_env(t_bst *bst)
{
	int	i;
	int	j;
	char	**path_split;

	i = 0;
	j = 0;
	bst->executor->execute_sign = 0;
	while (ft_strncmp(bst->my_env[i], "PATH", 4) != 0)
		i++;
	path_split = ft_split(bst->my_env[i] + 5, ':');
	while (bst->executor->cmd[j] && bst->executor->execute_sign == 0)
	{
		join_and_check_path(bst, path_split, bst->executor->cmd[j]);
		j++;
	}
	ft_free2d(path_split);
}

void	executor(t_bst *bst)
{
	split_path_form_env(bst);
	execve(bst->executor->execute_path, bst->executor->cmd, bst->my_env);
}
