/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 01:51:27 by tponark           #+#    #+#             */
/*   Updated: 2022/09/10 18:20:51 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_overflow(int result, int negative, int i, const char *nptr)
{
	if (result > 2147483647 / 10
		|| (result == 2147483647 / 10 && nptr[i] - '0' > 7))
	{
		if (nptr[i] - '0' == 8)
			return (-2147483648);
		if (negative == 1)
			return (-1);
		else if (negative == -1)
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int		result;
	int		negative;
	int		i;

	result = 0;
	negative = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '-')
	{
		negative = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		if (ft_overflow(result, negative, i, nptr) != 1)
			return (ft_overflow(result, negative, i, nptr));
		result = 10 * result + (nptr[i] - 48);
		i++;
	}
	return (negative * result);
}
