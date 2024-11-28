/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:37:46 by marvin            #+#    #+#             */
/*   Updated: 2024/11/28 11:37:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

static void	env_n_free(t_env_list *t)
{
	free(t->var);
	free(t);
	return ;
}

static t_env_list	*env_node_delete(t_env_list *env)
{
	t_env_list	*tmp;

	if (!env)
		return (NULL);
	if (env->next == NULL && env->previous == NULL)
		return (env_n_free(env), NULL);
	else if (env->previous == NULL)
	{
		tmp = env->next;
		env_n_free(env);
		tmp->previous = NULL;
		return (tmp);
	}
	else if (env->next == NULL)
	{
		tmp = env->previous;
		env_n_free(env);
		tmp->next = NULL;
		return (tmp);
	}
	else
	{
		tmp = env->next;
		env->previous->next = tmp;
		tmp->previous = env->previous;
		return (env_n_free(env), tmp);
	}
}

void	my_unset(t_all *all)
{
	char		*tmp;
	t_env_list	*e;

	e = all->env;
	if (all->cmd->cmd[2])
	{
		perror("syntax error\n");
		return ;
	}
	while (e->previous != NULL)
		e = e->previous;
	tmp = ft_strdup(all->cmd->cmd[1]);
	ft_strlcat(tmp, "=", ft_strlen(all->cmd->cmd[1]) + 2);
	while (strncmp(e->var, tmp, ft_strlen(all->cmd->cmd[1]) + 1) != 0
		&& e != NULL)
		e = e->next;
	if (e != NULL)
		e = env_node_delete(e);
	free(tmp);
}
