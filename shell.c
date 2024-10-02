/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:06:54 by marvin            #+#    #+#             */
/*   Updated: 2024/10/02 00:08:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

int	main(int arc, char **arv, char **envp)
{
	char		*input;
	char		*prompt;
	t_token		*token;
	t_cmd		*c;
	int			i;

	if (arc == 0)
		return (1);
    while (1)
    {
        input = readline("write something : ");
        if (input == NULL) 
            break;
        if (ft_strncmp(input, "exit", ft_strlen(input)) == 0) 
		{
            free(input);
            break;
        }
        if (*input) 
            add_history(input);
		token = tokenizer(input);
		c = parser(token);
		while (c->next != NULL)
		{
			i = 0;
			while (c->cmd[i])
			{
				printf("%s\n", c->cmd[i]);
				i++;
			}
			c = c->next;
		}
		cmd_l_free(c);
		total_free(token);
    }
    return 0;
}
