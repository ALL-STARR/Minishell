/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:07:24 by marvin            #+#    #+#             */
/*   Updated: 2024/09/13 15:07:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

t_env_list	*envellope(char **env)
{
	t_env_list	*envl;
	t_env_list	*first;
	int			i;

	envl = (t_env_list *)malloc(sizeof(t_env_list));
	if (!envl)
		return (NULL);
	i = 0;
	first = envl;
	while (env[i])
	{
		envl->variable = env[i];
		i++;
		if (env[i])
			envl = new_node(envl);
		if (!envl)
			return (NULL);
	}
	return (first);
}

t_env_list	*new_node(t_env_list *l)
{
	t_env_list	*new;

	new = (t_env_list *)malloc(sizeof(t_env_list));
	if (!new)
		return (NULL);
	if (!l)
		return (new);
	l->next = new;
	new->next = NULL;
	return (new);
}

void	env_l_free(t_env_list *l)
{
	t_env_list	*tmp;

	while (l->next != NULL)
	{
		tmp = l->next;
		free(l);
		l = tmp;
	}
	free(l);
	return ;
}

char	*variable_fetch(t_env_list *e, char *str)
{
	while (e->next == NULL)
	{
		if (ft_strnstr(e->variable, str, ft_strlen(e->variable)))
			return (e->variable);
		e = e->next;
	}
	return (NULL);
}
