/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:54:24 by thomvan-          #+#    #+#             */
/*   Updated: 2024/09/13 15:49:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list	*l;

	if (!lst)
		return ;
	if (!lst)
	{
		lst = new;
		return ;
	}
	l = lst;
	while (l->next != NULL)
		l = l->next;
	l->next = new;
}
