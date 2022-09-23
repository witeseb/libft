/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 03:50:37 by tponark           #+#    #+#             */
/*   Updated: 2022/09/06 05:17:01 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_l;

	if (size < 1)
		return (ft_strlen(src) + size);
	dst_l = ft_strlen(dst);
	if (dst_l >= size)
		return (ft_strlen(src) + size);
	while (*src && dst_l < size - 1)
		dst[dst_l++] = *src++;
	dst[dst_l] = '\0';
	return (ft_strlen(src) + dst_l);
}
