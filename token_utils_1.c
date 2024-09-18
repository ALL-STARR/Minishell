/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:15:34 by thomvan-          #+#    #+#             */
/*   Updated: 2024/09/18 17:19:00 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

/*checks if the current token is between 2 nodes with quotes*/

void	type_assign(t_token *t)
{	
	while (t->next != NULL)
	{
		if (!tok_is_in_dquote(t) && !tok_is_in_quote(t) 
			&& sym_check(t->content) < GENERAL)
			t->type = sym_check(t->content);
		else
			t->type = 6;
		t = t->next;
	}
	if (!tok_is_in_dquote(t) && !tok_is_in_quote(t) 
			&& sym_check(t->content) < 6)
			t->type = sym_check(t->content);
		else
			t->type = 6;
}

/*function to make tok_is_in_(d)quotes() shorter*/

void	quote_add(t_token *t, int *q, int *start, int *end)
{
	if (*q++ % 2 == 0)
		*start = t->index;
	else
		*end = t->index;
}