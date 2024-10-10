/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 04:11:24 by marvin            #+#    #+#             */
/*   Updated: 2024/10/10 04:11:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

/*pwd*/

void my_pwd()
{
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
        fprintf(stdout, "%s", cwd);
	else 
        perror("getcwd error");
}

/*echo*/

void	my_echo(char **arg)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (arg[i] == ft_strncmp(arg[i], "-n", 2))
		flag = 1;
	while (arg[i + flag] != NULL)
	{
		printf("%s", arg[i]);
		i++;
	}
	if (!flag)
		printf("\n");
}

/* cd */

void	my_cd(char **cmd)
{
	int	err;

	err = chdir(cmd[1]);
	if (err == -1)
		perror("path invalid");
}

/*export*/

void	my_export(t_all *all)
{
	int	i;

	i = 1;
	while (all->env->next != NULL)
		all->env = all->env->next;
	while (all->cmd[i] != NULL && var_value(all->cmd[i]))
	{
		all->env = new_node(all->env);
		all->env->var = all->cmd[i];
		i++;
	}
	if (!var_value(all->cmd[i]))
		printf("syntax error");
}

/*env*/

void	my_env(t_all *all, t_cmd *cmd)
{
	if (cmd[1])
		return (printf("too many arguments\n"), );
	while (all->env != NULL)
	{
		printf("%s\n", all->env->var);
		all->env = all->env->next;
	}
}
