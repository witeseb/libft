/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 06:15:35 by tponark           #+#    #+#             */
/*   Updated: 2022/09/11 08:24:32 by tponark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*this;
	t_list	*next;

	if (!del || !lst)
		return ;
	this = *lst;
	while (this)
	{
		next = this->next;
		ft_lstdelone(this, del);
		this = next;
	}
	*lst = NULL;
}
