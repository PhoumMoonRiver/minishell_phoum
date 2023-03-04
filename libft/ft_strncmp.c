/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:47:11 by njerasea          #+#    #+#             */
/*   Updated: 2023/03/04 19:13:08 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strncmp(char *src, char *des, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (src[i] - des[i] != 0)
			return (src[i] - des[i]);
		i++;
	}
	return (0);
}
