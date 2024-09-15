/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:10:50 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 13:10:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

//Still need to implement $ handeling

t_token	*tokenizer(char	*input)
{
	char	**chop;
	t_token	*token_list;
	
	input = spacer(input);
	chop = ft_split(input, ' ');
	token_list = token_node(chop);
	double_array_free(chop);
	return (token_list);
}

/*adds the elements of the double array into the token list*/

t_token	*token_node(char **chopped)
{
	t_token *tok;
	t_token *first;

	int	i;

	tok = (t_token *)malloc(sizeof(t_token ));
	if (!tok)
		return (NULL);
	i = 0;
	first = tok;
	while (chopped[i])
	{
		tok->content = chopped[i];
		tok->type = sym_check(tok->content);
		i++;
		if (chopped[i])
			tok = new_node(tok);
		if (!tok)
			return (NULL);
	}
	return (first);
}

/*creates a new token node for the list*/

t_token	*new_t_node(t_token *l)
{
	t_token *new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	if (!l)
	{
		new->next = NULL;
		new->previous = NULL;
		return (new);
	}
	l->next = new;
	new->next = NULL;
	new->previous = l;
	return (new);
}

/*frees the token list*/

void	token_l_free(t_token *t)
{
	t_token *tmp;

	while (t->next != NULL)
	{
		tmp = t->next;
		free(l);
		t = tmp;
	}
	free(l);
	return ;
}

/*indentifies the special character*/

int	sym_check(char *input)
{
	int i;

	i = 0:
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
	return (6);
}

/*calculates the size needed for the new spaced string*/

int	size_count(char *str)
{
	int	i;
	int	size;

	i = 0;
	while (str[i])
	{
		if (sym_check(str + i) < 4)
		{
			size += 2;
			if (sym_check(str + i) == 5 || sym_check(str + i) == 4)
				i++;
			i++;
		}
	}
	return (size += i);
}

/*creates a new string with ' ' separating each elements for further splitting*/

char	*spacer(char *s)
{
	char	*spaced;
	int		i;
	int		j;

	i = 0;
	j = 0;
	spaced = malloc(sizeof(char) * size_count(str));
	if (!spaced)
		return (NULL);
	while (s[i])
	{
		if (!dquoted(s, i) && !dquoted(s, i) && sym_check(str + i) < 6)
		{
			spaced[j++] = ' ';
			spaced[j++] = s[i++];
			if (s[i - 1] == s[i] && sym_check(str + i) < 3)
				spaced[j++] = s[i++];
			spaced[j++] = ' ';
		}
		else
			spaced[j++] = s[i++];
	}
	free(s);
	spaced[j] = '\0';
	return (spaced);
}

/*detects if the character is between double-quotes*/

int	dquoted(char *s, int index)
{
	int	i;
	int	dquotes_open;
	int	dquotes_closed;
	int	how_many;
	
	i = 0;
	how_many = 0;
	while (s[i])
	{
		if (s[i] == 34)
		{
			how_many++;
			if (how_many % 2 == 1)
				dquotes_open = i;
			else
				dquotes_closed = i;
		}
		if (index < dquotes_closed && index > dquotes_open)
			return (1);
		i++;
	}
	return (0);
}

/*detects if the character is between quotes*/

int	quoted(char *s, int index)
{
	int	i;
	int	dquotes_open;
	int	dquotes_closed;
	int	how_many;
	
	i = 0;
	how_many = 0;
	while (s[i])
	{
		if (s[i] == 39)
		{
			how_many++;
			if (how_many % 2 == 1)
				dquotes_open = i;
			else
				dquotes_closed = i;
		}
		if (index < dquotes_closed && index > dquotes_open)
			return (1);
		i++;
	}
	return (0);
}

void	double_array_free(char **a)
{
	int	i;
	int	j;

	i = 0;
	while (a[i])
		free(a[i]);
	free[a];
	return ;
}

/* int	sym_finder(char *input)
{
	int	i;

	int = 0;
	while (input[i] != '<' && input[i] != '>'
		&& input[i] != '|' && input[i])
		i++;
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
	return (-1);
} */