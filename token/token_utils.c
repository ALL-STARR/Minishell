/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:05:57 by thomvan-          #+#    #+#             */
/*   Updated: 2024/09/18 19:43:31 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

/*indentifies the special character*/

int	sym_check(char *input)
{
	int	i;

	i = 0;
	if (input[i] == '<' && input[i + 1] == '<')
		return (4);
	if (input[i] == '>' && input[i + 1] == '>')
		return (5);
	if (input[i] == '<')
		return (1);
	if (input[i] == '>')
		return (2);
	if (input[i] == '|')
		return (3);
	if (input[i] == 39)
		return (6);
	if (input[i] == 34)
		return (7);
	return (8);
}

/*checks for quotes in the previous and next(s) nodes*/

int	tok_is_in_dquote(t_token *token)
{
	int	dquote;
	int	dquote_i_start;
	int	dquote_i_end;
	int	index;

	dquote = 0;
	dquote_i_end = -1;
	dquote_i_start = 0;
	index = token->index;
	while (token->previous != NULL)
		token = token->previous;
	while (token->next != NULL)
	{
		if (*token->content == 34)
		{
			quote_add(token, &dquote, &dquote_i_start, &dquote_i_end);
			if (index > dquote_i_start && index < dquote_i_end)
				return (1);
		}
		token = token->next;
	}
	if (*token->content == 34 && index > dquote_i_start)
		return (1);
	return (0);
}

/*checks for dquotes in the previous and next(s) nodes*/

int	tok_is_in_quote(t_token *token)
{
	int	quote;
	int	quote_i_start;
	int	quote_i_end;
	int	index;

	quote = 0;
	quote_i_end = -1;
	quote_i_start = 0;
	index = token->index;
	while (token->previous != NULL)
		token = token->previous;
	while (token->next != NULL)
	{
		if (*token->content == 39 && !tok_is_in_dquote(token))
		{
			quote_add(token, &quote, &quote_i_start, &quote_i_end);
			if (index >= quote_i_start && index <= quote_i_end)
				return (1);
		}
		token = token->next;
	}
	if (*token->content == 39 && index > quote_i_start)
		return (1);
	return (0);
}
