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

/*detects if the character is between quotes or double-quotes*/

int	quoted(char *s, int index)
{
	int	i;
	int	dquotes_open;
	int	dquotes_closed;
	int	quote;

	i = 0;
	dquotes_open = 0;
	dquotes_closed = 0;
	while (s[i])
	{
		if ((s[i] == 34 && ft_strchr(s + (i + 1), 34))
			|| (s[i] == 39 && ft_strchr(s + (i + 1), 39)))
		{
			quote = s[i];
			dquotes_open = i;
			while (s[++i] != quote)
				i;
			dquotes_closed = i;
		}
		if (index < dquotes_closed && index > dquotes_open)
			return (1);
		dquotes_closed = 0;
		i++;
	}
	return (0);
}