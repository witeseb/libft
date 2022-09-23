/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:07:40 by tponark           #+#    #+#             */
/*   Updated: 2022/09/10 18:14:20 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getlen(long nbr)
{
	size_t	size;

	size = 0;
	if (nbr <= 0)
		size++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

static char	*ft_fill(size_t size, size_t i, long nbr, char	*str)
{
	str[size] = '\0';
	while (size > i)
	{
		str[size - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		size--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	size;
	size_t	i;
	char	*str;
	long	nbr;

	i = 0;
	nbr = n;
	size = ft_getlen(nbr);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
		i = 1;
	}
	str = ft_fill(size, i, nbr, str);
	return (str);
}

/*
change these, use long instead of int to solve to "TOO LONG" norm.
*/

/*
if (n == 2147483647)
	{
		str[0] = '2';
		n = 147483647;
		i = 1;
	}
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
		i = 2;
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i = 1;
	}
*/
