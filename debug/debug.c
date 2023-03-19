/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:51:50 by njerasea          #+#    #+#             */
/*   Updated: 2023/03/19 14:22:23 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_d_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("This is **str ==> |%s|\n", str[i]);
		i++;
	}
	exit(0);
}

void	print_single_str(char *str)
{
	printf("This is single str ==> |%s|\n", str);
	exit(0);
}

void	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("This is *str ==> |%c|\n", str[i]);
		i++;
	}
	exit(0);
}
