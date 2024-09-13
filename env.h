/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:10:44 by marvin            #+#    #+#             */
/*   Updated: 2024/07/27 14:09:01 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>

typedef struct s_env_list
{
	char 				*variable;
	struct s_env_list	*next;
}	t_env_list;

t_env_list	*envellope(char **env);
t_env_list	*new_node(t_env_list *l);
void		env_l_free(t_env_list *l);

#endif