/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 01:30:09 by tponark           #+#    #+#             */
/*   Updated: 2022/09/08 01:34:56 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*ptr;

	str = (char *)malloc(ft_strlen(s) + 1);
	ptr = str;
	if (!ptr)
		return (0);
	while (*s)
		*ptr++ = *s++;
	*ptr = '\0';
	return (str);
}
