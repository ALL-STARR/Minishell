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

#include "../includes/shell.h"

/*frees the lists*/

void	total_free(t_token *t)
{
	token_l_free(t);
	return ;
}

/*deletes one token of the list*/

t_token	*token_delete(t_token *t)
{
	t_token *tmp;

	if (t->next == NULL && t->previous == NULL)
		return (token_free(t), NULL);
	else if (t->previous == NULL)
	{
		tmp = t->next;
		tmp->previous = NULL;
		return (token_free(t), tmp);
	}
	else if (t->next == NULL)
	{
		tmp = t->previous;
		token_free(t);
		tmp->next = NULL;
		return (NULL);
	}
	else
	{
		tmp = t->next;
		t->previous->next = tmp;
		tmp->previous = t->previous;
		return (token_free(t), tmp);
	}
}

/*frees token*/

void	token_free(t_token *t)
{
	free(t->content);
	free(t);
	return ;
}

int	not_a_split(char *s, char sep, int index)
{
	if (quoted(s, index) || s[index] != sep)
		return (1);
	else
		return (0);
}