/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:58:23 by tponark           #+#    #+#             */
/*   Updated: 2022/09/08 01:21:19 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (!little[0])
		return ((char *)big);
	if (len < 1)
		return (NULL);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] && little[j] == big[i + j] && (i + j < len))
			{
				j++;
			}
			if (!little[j])
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
