/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 01:39:39 by marvin            #+#    #+#             */
/*   Updated: 2023/11/14 01:39:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*start;
	void	*cont_tmp;

	if (!del || !f || !lst)
		return (NULL);
	start = NULL;
	while (lst)
	{
		cont_tmp = f(lst->content);
		l = ft_lstnew(cont_tmp);
		if (!l)
		{
			del(cont_tmp);
			ft_lstclear(&l, (*del));
			return (start);
		}
		ft_lstadd_back(&start, l);
		lst = lst->next;
	}
	return (start);
}
