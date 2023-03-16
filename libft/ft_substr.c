/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:20:53 by njerasea          #+#    #+#             */
/*   Updated: 2023/03/10 16:21:16 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new;
	size_t		i;
	size_t		l;

	i = 0;
	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (l >= len)
		new = (char *)malloc(len + 1);
	else
		new = (char *)malloc(l + 1);
	if (!new)
		return (NULL);
	while (start < l && i < len)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
