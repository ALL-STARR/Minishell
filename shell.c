/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:06:54 by marvin            #+#    #+#             */
/*   Updated: 2024/09/16 16:06:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "shell.h"

int	main(int arc, char **arv, char **envp)
{
	char		*input;
	t_env_list	*evp_list;
	t_token		*token_list;

	if (arc == 0)
		return ;
	envp_list = envellope(envp);
	input = readline("write something idk '\\_(-_-)_/' :");
	add_history(char input);
	
}