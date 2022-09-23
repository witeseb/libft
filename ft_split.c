/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 02:39:54 by tponark           #+#    #+#             */
/*   Updated: 2022/09/10 03:58:51 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_total(const char *s, char c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static size_t	ft_word(const char *s, char c, size_t word_l)
{
	if (!ft_strchr(s, c))
		word_l = ft_strlen(s);
	else
		word_l = ft_strchr(s, c) - s;
	return (word_l);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	size_t	word_l;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	word_l = ft_strlen(s);
	array = malloc((ft_total(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			word_l = ft_word(s, c, word_l);
			array[i++] = ft_substr(s, 0, word_l);
			s += word_l;
		}
	}
	array[i] = NULL;
	return (array);
}
