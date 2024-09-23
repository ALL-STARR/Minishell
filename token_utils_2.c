/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:58:55 by marvin            #+#    #+#             */
/*   Updated: 2024/09/20 16:58:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

/*frees the lists*/

void	total_free(t_token *t, t_env_list *e)
{
	void		env_l_free(e);
	void		token_l_free(t);
	return ;
}

/*deletes one token of the list*/

int	token_delete(t_token *t)
{
	t_token *tmp1;

	if (t->previous == NULL)
	{
		tmp1 = t->next;
		tmp1->previous = NULL;
		return (free(t->content), free(t), 1);
	}
	else if (t->next == NULL)
	{
		tmp1 = t->previous;
		tmp1->next = NULL;
		return (free(t->content), free(t), 1);
	}
	else if (t->next == NULL && t->previous == NULL)
		return (free(t->content), free(t), 1);
	else
	{
		t->next->previous = t->previous
		return (free(t->content), free(t), 1);
	}
}