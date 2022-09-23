/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 02:07:04 by tponark           #+#    #+#             */
/*   Updated: 2022/09/10 02:22:57 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*ptr;
	size_t	i;
	size_t	f;

	if (!s1)
		return (NULL);
	i = 0;
	f = ft_strlen(s1);
	while (s1[i] && ft_checkset(s1[i], set))
		i++;
	while (f > i && ft_checkset(s1[f - 1], set))
		f--;
	str = (char *)malloc(f - i + 1);
	if (!str)
		return (NULL);
	ptr = str;
	while (i < f)
		*str++ = s1[i++];
	*str = '\0';
	return (ptr);
}
