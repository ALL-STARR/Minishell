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
	char	*str;
	int		index;
	t_token	*first;

	first = all->token;
	index = -1;
	while (all->token)
	{
		if (all->token->type == DOUBLE_SMALL)
			index = all->token->index;
		all->token = all->token->next;
	}
	all->token = first;
	while (index && all->token->index != index)
		all->token = all->token->next;
	if (index)
	{
		all->token = token_delete(all->token);
		str = all->token->content;
		all->token->content =; //heredoc_function
		free(str);
	}
	all->token = first;
}
