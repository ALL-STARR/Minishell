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
