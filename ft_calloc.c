/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 01:36:48 by tponark           #+#    #+#             */
/*   Updated: 2022/09/19 20:19:25 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == SIZE_MAX || size == SIZE_MAX)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
