/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:21:47 by rachou            #+#    #+#             */
/*   Updated: 2024/10/26 15:21:53 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

int	main(int arc, char **arv, char **envp)
{
	char		*input;
	char		*prompt;
	t_token		*tok;
	t_cmd		*c;
	t_all		*all;
	int			i;

	if (arc == 0)
		return (1);
	while (1)
	{
		input = readline("write something : ");
		if (input == NULL)
			return(1);
		if (ft_strncmp(input, "exit", ft_strlen(input)) == 0) 
		{
			free(input);
			printf("exit\n");
			return (1);
		}
		all = (t_all *)malloc(sizeof(t_all));
		if (*input) 
			add_history(input);
		all->env = envellope(envp);
		all->token = tokenizer(input, all);
		all->cmd = parser(all->token);
		ft_pipe(arc, all->cmd, all->env);
		//token_list_visualizer(all);
		//cmd_list_visualizer(all);
	}
	clear_history();
	total_free(all);
    return 0;
}
