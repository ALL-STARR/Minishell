/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:57:10 by marvin            #+#    #+#             */
/*   Updated: 2023/11/14 00:57:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;

	if (!del || !lst)
		return ;
	while (lst && (*lst))
	{
		l = (*lst)->next;
		ft_lstdelone((*lst), del);
		(*lst) = l;
	}
}
