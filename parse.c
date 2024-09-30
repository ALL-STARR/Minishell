/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:02:12 by marvin            #+#    #+#             */
/*   Updated: 2024/09/24 14:02:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

int	parser(t_cmd_len *t)
{
	t_cmd	*command;
	int		how_many;
	int		pipes;

	how_many = 0;
	command = (t_cmd *)malloc(sizeof(t_cmd));
	if (!command)
		return (-1);
}

/*creates cmd_nodes and fills them with the commands*/

t_cmd	*cmd_node(t_token *t, t_cmd *cmd_l)
{
	int		i;

	cmd_l->previous = NULL;
	cmd_l->next = NULL;
	i = 0;
	cmd_l->cmd = malloc(sizeof(char *) * (word_count(t) + 1));
	if (!command->cmd)
		return (NULL);
	while (t->next != NULL)
	{
		if (t->type != PIPE)
			cmd_l->cmd[i] = t->content;
		i++;
		t = t->next;
		if (t->type == PIPE)
		{
			t = t->next; /*if there is a pipe in the parsing it means that there where multiple pipes back to back*/
			cmd_l = new_c_node(cmd_l);
			if (!cmd_l)
				return (NULL);
			i = 0;
		}
	}
	return ();
}

/*counts the number of words before the next PIPE*/

int	word_count(t_token *t)
{
	int	i;

	i = 0;
	while (t->next != NULL && t->type != PIPE)
		i++;
	if (t->type != PIPE)
		i++;
	return (i);
}

/*creates a new cmd_node and returns it*/

t_cmd	*new_c_node(t_cmd *c)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	if (!l)
	{
		new->next = NULL;
		new->previous = NULL;
		return (new);
	}
	c->next = new;
	new->next = NULL;
	new->previous = c;
	return (new);
}
