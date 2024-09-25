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

#include "../includes/shell.h"

/*int	main()
{
	t_token *t;

	t = tokenizer("He>>l\"omy |'love'\"");
	printf("Hell\"omy|love'\"\n");
	while (t->next != NULL)
	{
		printf("%s type is %d and index is : %d\n\n", t->content, t->type, t->index);
		t = t->next;
	}
	printf("%s type is %d and index is : %d\n\n", t->content, t->type, t->index);
	token_l_free(t);
}*/

//Still need to implement $ handling

t_token	*tokenizer(char	*input)
{
	char	**chop;
	t_token	*token_list;

	input = spacer(input);
	chop = s_split(input, ' ');
	token_list = token_node(chop);
	if (token_list == NULL)
		return (NULL);
	type_assign(token_list);
	free(input);
	free(chop);
	return (token_list);
}

/*adds the elements of the double array into the token list*/

t_token	*token_node(char **chopped)
{
	t_token	*tok;
	t_token	*first;
	int		i;

	tok = (t_token *)malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->previous = NULL;
	tok->next = NULL;
	i = 0;
	first = tok;
	while (chopped[i])
	{
		tok->content = chopped[i];
		tok->type = 0;
		tok->index = i;
		i++;
		if (chopped[i])
			tok = new_t_node(tok);
		if (!tok)
			return (NULL);
	}
	return (first);
}

/*creates a new token node for the list*/

t_token	*new_t_node(t_token *l)
{
	t_token	*new;

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

/*creates a new string with ' ' separating each elements for further splitting*/

char	*spacer(char *s)
{
	char	*spaced;
	int		i;
	int		j;
	int		quote;

	i = 0;
	j = 0;
	spaced = malloc(sizeof(char) * (size_count(s) + 1));
	if (!spaced)
		return (NULL);
	while (s[i])
	{
		if (sym_check(s + i) < GENERAL && !quoted(s, i))
		{
			printf("quoted = %d and i = %d\n", quoted(s, i), i);
			spaced[j++] = ' ';
			spaced[j++] = s[i++];
			if (s[i - 1] == s[i] && sym_check(s + i) < 3)
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

/*frees the token list*/

void	token_l_free(t_token *t)
{
	t_token	*tmp;

	while (t->previous != NULL)
		t = t->previous;
	while (t->next != NULL)
	{
		tmp = t->next;
		free(t->content);
		free(t);
		t = tmp;
	}
	free(t->content);
	free(t);
	return ;
}
