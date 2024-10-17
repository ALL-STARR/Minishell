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

#include "../includes/shell.h"

t_cmd	*parser(t_token *t)
{
	t_cmd	*command;
	int		how_many;
	int		pipes;

	how_many = 0;
	command = (t_cmd *)malloc(sizeof(t_cmd));
	if (!command)
		return (NULL);
	command->previous = NULL;
	command->next = NULL;
	redirect_finder(t, command);
	command = cmd_node(t, command);
	return (command);
}

/*factorisation of next function (cmd_node)*/

static void	cmd_node_pipe_short(t_token *t, t_cmd *cmd_l, int *i)
{
	t = t->next;
	cmd_l->cmd[*i] = NULL;
	cmd_l = new_c_node(cmd_l, t);
	if (!cmd_l)
		return (NULL);
	*i = 0;
}

/*creates cmd_nodes and fills them with the commands*/

t_cmd	*cmd_node(t_token *t, t_cmd *cmd_l)
{
	int		i;
	t_cmd	*first;

	i = 0;
	cmd_l->cmd = malloc(sizeof(char *) * (word_count(t) + 1));
	if (!cmd_l->cmd)
		return (NULL);
	first = cmd_l;
	cmd_l->in_red = NULL;
	cmd_l->out_red = NULL;
	while (t->next != NULL)
	{
		if (t->type != PIPE)
			cmd_l->cmd[i++] = t->content;
		t = t->next;
		if (t->type == PIPE)
			cmd_node_pipe_short(t_token *t, t_cmd *cmd_l, &i);
	}
	if (t->type != PIPE)
	{
		cmd_l->cmd[i++] = t->content;
		cmd_l->cmd[i++] = NULL;
	}
	return (first);
}

/*counts the number of words before the next PIPE*/

int	word_count(t_token *t)
{
	int	i;

	i = 0;
	while (t->next != NULL && t->type != PIPE)
	{
		t = t->next;
		i++;
	}
	if (t->type != PIPE)
		i++;
	return (i);
}

/*creates a new cmd_node and returns it*/

t_cmd	*new_c_node(t_cmd *c, t_token *t)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->cmd = malloc(sizeof(char *) * (word_count(t) + 1));
	if (!new->cmd)
		return (NULL);
	c->next = new;
	new->next = NULL;
	new->in_red = NULL;
	new->out_red = NULL;
	new->previous = c;
	return (new);
}

void	cmd_l_free(t_cmd *c)
{
	t_cmd	*tmp;

	while (c->previous != NULL)
		c = c->previous;
	while (c->next != NULL)
	{
		if (c->in_red)
			free(c->in_red);
		if (c->out_red)
			free(c->out_red);
		free(c->cmd);
		tmp = c;
		c = c->next;
		free(tmp);
	}
	if (c->in_red)
		free(c->in_red);
	if (c->out_red)
		free(c->out_red);
	free(c->cmd);
	free(c);
	c->cmd = 0;
	c->next = 0;
	c->previous = 0;
	system("leaks minishell");
}
