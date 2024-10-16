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
	t_cmd	*first;

	c->n_redirection = 0;
	while (t)
	{
		if (t->type == SMALLER || t->type == DOUBLE_SMALL)
		{
			c->n_redirection++;
			c->in_red = t;
			c->in_red->next = t->next;
			t->previous->next = t->next->next;
			t = t->next;
		}
		if (t->type == GREATER || t->type == DOUBLE_GREAT)
		{
			c->n_redirection++;
			c->out_red = t;
			c->out_red->next = t->next;
			t->previous->next = t->next->next;
			t = t->next;
		}
		t = t->next;
	}
	return (n_red);
}