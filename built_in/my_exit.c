/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:38:29 by thomvan-          #+#    #+#             */
/*   Updated: 2024/11/30 12:19:55 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

static int	is_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

void	my_exit(t_all *all, t_cmd *c)
{
	int	i;
	int	tmp;

	i = 1;
	if (!c->cmd[1] || c->cmd[2])
	{
		printf("please provide only one numeric argument\n");
		g_err_global = 1;
		return ;
	}
	while (c->cmd[i])
	{
		if (!is_digit(c->cmd[i]))
		{
			printf("error : argument is not a number\n");
			g_err_global = 1;
			return ;
		}
		i++;
	}
	tmp = ft_atoi(c->cmd[1]) % 256;
	g_err_global = tmp;
	total_free(all);
	exit(tmp);
}
