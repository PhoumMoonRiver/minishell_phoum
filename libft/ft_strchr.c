/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:13:15 by njerasea          #+#    #+#             */
/*   Updated: 2023/03/10 16:14:19 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strchr(const char *s, int c)
{
	char	focus;

	focus = (char)c;
	while (*s && focus != *s)
		s++;
	if (focus == *s)
		return ((char *)s);
	return (NULL);
}
