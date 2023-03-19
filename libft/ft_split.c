/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:30:37 by njerasea          #+#    #+#             */
/*   Updated: 2023/03/18 17:46:59 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_word(char *str, char del)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] == del && str[i])
			i++;
	while (str[i])
	{
		count++;
		while (str[i] != del && str[i])
			i++;
		while (str[i] == del && str[i])
			i++;
	}
	return (count);
}

int	len_count(char *w, char c)
{
	int	i;

	i = 0;
	while (w[i] != c && w[i])
		i++;
	return (i);
}

char    *len_assign(char *str, char del)
{
	int	i;
	int	len;
	char	*mini_splited;

	i = 0;
	len = len_count(&str[i], del);
	mini_splited = (char *)malloc(sizeof(char) * len + 1);
	if (!mini_splited)
		return (NULL);
	while (i < len)
	{
		mini_splited[i] = str[i];
		i++;
	}
	mini_splited[len] = '\0';
	return (mini_splited);
}

char	**ft_input_valus(char *str, char del, char **splited)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] == del && str[i])
		i++;
	while (str[i])
	{
		splited[j] = len_assign(&str[i], del);
		j++;
		while (str[i] != del && str[i])
			i++;
		while (str[i] == del && str[i])
			i++;
	}
	return (splited);
}

char	**ft_split(char *str, char del)
{
	int	word;
	char	**splited;

	if (!str)
		return (NULL);
	word = count_word(str, del);
	splited = (char **)malloc(sizeof(char *) * (word + 1));
	if (!splited)
		return (NULL);
	splited[word] = NULL;
	splited = ft_input_valus(str, del, splited);
	return (splited);
}
