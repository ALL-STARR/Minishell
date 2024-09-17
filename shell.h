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

#ifndef SHELL_H
# define SHELL_H

//# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_env_list
{
	char 				*variable;
	struct s_env_list	*next;
}	t_env_list;

typedef struct s_token
{
	char			*content;
	int 			type;
	struct s_token	*next;
	struct s_token	*previous;
}	t_token;

# define GENERAL -1
# define CHAR_SMALLER_THAN 1
# define CHAR_GREATER_THAN 2
# define DOUBLE_SMALL 3
# define DOUBLE_GREAT 4
# define PIPE 5

/*environment_list functions*/

t_env_list	*envellope(char **env);
t_env_list	*new_node(t_env_list *l);
void		env_l_free(t_env_list *l);


/*token functions*/

t_token		*new_t_node(t_token *l);
void		token_l_free(t_token *t);
t_token		*token_node(char **chopped);
int			sym_finder(char *input);
int			sym_check(char *input);
int			size_count(char *str);
char		*spacer(char *s);
int			dquoted(char *s, int index);
int			quoted(char *s, int index);
void		double_array_free(char **a);
t_token		*tokenizer(char	*input);

#endif