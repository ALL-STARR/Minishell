/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:24:19 by thomvan-          #+#    #+#             */
/*   Updated: 2024/10/08 15:51:39 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

void	spacer_shortcut(char *spac, char *s, int *i, int *j)
{
	spac[(*j)++] = ' ';
	spac[(*j)++] = s[(*i)++];
	if (s[(*i) - 1] == s[(*i)] && sym_check(s + (*i)) < 3)
		spac[(*j)++] = s[(*i)++];
	spac[(*j)++] = ' ';
}

void	replace_here(t_all *all)
{
	t_token *first;

	first = all->token;
	while (all->token != NULL)
	{
		if (all->token->type == DOUBLE_SMALL)
		{
			token_delete(all->token);
			free(all->token->content);
			all->token->content = //heredocfunction();
		}
		all->token = all->token->next;
	}
	all->token = first;
}

void redirect_finder(t_token *t, t_cmd *c)
{
	t_cmd *first;

	while (t)
	{
		if (t->type < 5)
		{
			c->redirect = t;
			c->redirect->next = t->next;
			t->previous = t->next->next;
		}
	}
}