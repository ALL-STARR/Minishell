/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:15:34 by thomvan-          #+#    #+#             */
/*   Updated: 2024/09/18 20:01:21 by thomvan-         ###   ########.fr       */
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
		is_command(t);
		t = t->next;
	}
	if (!tok_is_in_dquote(t) && !tok_is_in_quote(t)
		&& sym_check(t->content) < GENERAL)
		t->type = sym_check(t->content);
	else
		t->type = 6;
	is_command(t);
}

/*function to make tok_is_in_(d)quotes() shorter*/

void	quote_add(t_token *t, int *q, int *start, int *end)
{
	if (*q % 2 == 1)
		*start = t->index;
	else
		*end = t->index;
}

/*calculates the size needed for the new spaced string*/

int	size_count(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (sym_check(str + i) < 4)
		{
			size += 2;
			if (sym_check(str + i) == 5 || sym_check(str + i) == 4)
				i++;
		}
		i++;
	}
	return (size += i);
}

/*checks if the node is a command*/

int	is_command(t_token *t)
{
	const char	tab[7][6] = {"echo", "cd", "pwd", "export",
		"unset", "env", "exit"};
	int			i;

	i = 0;
	while (i < 7)
	{
		if (ft_strncmp(tab[i], t->content, ft_strlen(tab[i])) == 0)
			return (t->type = 9, 1);
		i++;
	}
	return (0);
}

void	quote_trim