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

# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_env_list
{
	char				*variable;
	struct s_env_list	*next;
}	t_env_list;

typedef struct s_token
{
	char			*content;
	int				type;
	int				index;
	struct s_token	*next;
	struct s_token	*previous;
}	t_token;

# define CHAR_SMALLER_THAN 1
# define CHAR_GREATER_THAN 2
# define PIPE 3
# define DOUBLE_SMALL 4
# define DOUBLE_GREAT 5
# define D_QUOTE 6
# define QUOTE 7
# define GENERAL 8
# define COMMAND 9

/*general functions*/

void		total_free(t_token *t, t_env_list *e);

/*environment_list functions*/

t_env_list	*envellope(char **env);
t_env_list	*new_node(t_env_list *l);
void		env_l_free(t_env_list *l);
char		*variable_fetch(t_env_list *e, char *str);

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
t_token		*tokenizer(char	*input);
int			tok_is_in_quote(t_token *token);
int			tok_is_in_dquote(t_token *token);
void		type_assign(t_token *t);
void		quote_add(t_token *t, int *q, int *start, int *end);
int			is_command(t_token *t);
int			token_delete(t_token *t);

#endif