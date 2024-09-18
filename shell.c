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

#include "includes/shell.h"

int	main(int arc, char **arv, char **envp)
{
	char		*input;
	char		*prompt;
	t_env_list	*evp_list;
	t_token		*token;
	t_token		*first_node;

	if (arc == 0)
		return (1);
	evp_list = envellope(envp);
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
		first_node = token;
		while (token->next != NULL)
		{
			printf("%s : %d index = %d -- ", token->content, token->type, token->index);
			token = token->next;
			printf("%s\n", token->previous->content);
		}
		printf("%s : %d index = %d -- \n", token->content, token->type, token->index);
		token_l_free(first_node);
		env_l_free(evp_list);
    }
    return 0;
}
