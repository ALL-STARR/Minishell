/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:20:25 by thomvan-          #+#    #+#             */
/*   Updated: 2024/10/20 17:21:38 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

char	*var_value(char *var)
{
	if (!var)
		return (NULL);
	while (*var != '=' && *var != '\0')
		var++;
	return (var);
}

void	redirect_finder(t_token *t, t_cmd *c)
{
	t_cmd	*first;
	int		in_flag;
	int		out_flag;

	c->n_redirection = 0;
	in_flag = 0;
	out_flag = 0;
	while (t)
	{
		if ((t->type == SMALLER)
			&& t->next->type > PIPE)
			in_red(t, c, &in_flag);
		if ((t->type == GREATER || t->type == DOUBLE_GREAT)
			&& t->next->type > PIPE)
			out_red(t, c, &out_flag);
		t = t->next;
	}
	return ;
}

void	in_red(t_token *t, t_cmd *c, int *in_flag)
{
	c->n_redirection++;
	if (*in_flag)
	{
		c->in_red->next = t;
		c->in_red = c->in_red->next;
	}
	else
		c->in_red = t;
	c->in_red->next = t->next;
	c->in_red = c->in_red->next;
	t->previous->next = t->next->next;
	*in_flag = 1;
	t = t->next;
}

void	out_red(t_token *t, t_cmd *c, int *out_flag)
{
	c->n_redirection++;
	if (*out_flag)
	{
		c->out_red->next = t;
		c->out_red = c->in_red->next;
	}
	else
		c->out_red = t;
	c->out_red->next = t->next;
	c->out_red = c->out_red->next;
	t->previous->next = t->next->next;
	*out_flag = 1;
	t = t->next;
}
