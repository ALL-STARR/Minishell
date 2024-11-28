/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:54:44 by marvin            #+#    #+#             */
/*   Updated: 2024/10/10 16:54:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

static void	env_split(t_all *all)
{
	t_env_list	*current;
	char		**env_rlt;

	current = all->env;
	while (current)
	{
		env_rlt = ft_split(current->var, '=');
		current->env_name = env_rlt[0];
		current->env_value = env_rlt[1];
		free(env_rlt);
		current = current->next;
	}
}

static void env_split_erase(t_env_list *e)
{
	t_env_list *tmp;

	tmp = e;
	while (tmp->previous != NULL)
		tmp = tmp->previous;
	while (tmp)
	{
		free(tmp->env_name);
		free(tmp->env_value); 
		tmp = tmp->next;
	}
	
}

/*void	tok_split(t_all *all)
{
	t_token		*next_content;
	char		**tok_rlt;

	next_content = all->token->next;
	tok_rlt = ft_split(next_content->content, '=');
	all->token->next->tok_name = tok_rlt[0];
	all->token->next->tok_value = tok_rlt[1];
}*/

void	my_export(t_all *all)
{
	t_env_list	*current;
	t_env_list	*new_node;
	t_token		*next_content;
	char		**tok_rlt;
	bool		found;

	current = all->env;
	next_content = all->token->next;
	if (!next_content)
	{
		while (current)
		{
			env_split(all);
			printf("declare -x %s", current->env_name);
			printf("=\"%s\"\n", current->env_value);
			free(current->env_name);
			free(current->env_value);
			current = current->next;
		}
		return ;
	}
	tok_rlt = ft_split(next_content->content, '=');
	next_content->tok_name = tok_rlt[0];
	next_content->tok_value = tok_rlt[1];
	found = false;
	while (current)
	{
		env_split(all);
		if (!ft_strcmp(tok_rlt[0], current->env_name))
		{
			if (ft_strcmp(tok_rlt[1], current->env_value) != 0)
			{
				free(current->env_value);
				current->env_value = ft_strdup(tok_rlt[1]);
				current->var = ft_strjoin(current->env_name, "=");
				current->var = ft_strjoin(current->var, current->env_value);
			}
			found = true;
			break ;
		}
		current = current->next;
	}
	if (!found)
	{
		new_node = malloc(sizeof(t_env_list));
		if (!new_node)
			return ;
		new_node->env_name = ft_strdup(tok_rlt[0]);
		new_node->env_value = ft_strdup(tok_rlt[1]);
		free(tok_rlt[0]);
		free(tok_rlt[1]);
		free(tok_rlt);
		new_node->var = ft_strjoin(new_node->env_name, "=");
		new_node->var = ft_strjoin(new_node->var, new_node->env_value);
		new_node->next = NULL;
		if (all->env == NULL)
		{
			all->env = new_node;
			new_node->previous = NULL;
		}
		else
		{
			current = all->env;
			while (current->next != NULL)
				current = current->next;
			current->next = new_node;
			new_node->previous = current;
		}
	}
	env_split_erase(all->env);
}

void	my_cd(char **cmd, t_all *all)
{
	int			err;
	char		*tmp;
	t_env_list	*cpy;
	int			i;
	static char	cwd[1024];	

	cpy = all->env;
	i = 0;
	if (!cmd[1])
	{
		printf("please insert absolute or relative path\n");
		return ;
	}
	else
		err = chdir(cmd[1]);
	if (err == -1)
		perror("chdir :");
	getcwd(cwd, sizeof(cwd));
	tmp = malloc(sizeof(char) * (ft_strlen(cwd) + 5));
	if (!tmp)
		return ;
	while (i < (ft_strlen(cwd) + 5))
		tmp[i++] = '\0';
	while (ft_strncmp(cpy->var, "PWD", 3) != 0
		&& cpy != NULL)
		cpy = cpy->next;
	if (cpy)
	{
		tmp = strncpy(tmp, "PWD=", 4);
		ft_strlcat(tmp, cwd, ft_strlen(cwd) + 5);
		free(cpy->var);
		cpy->var = tmp;
	}
}
