/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 02:45:34 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 02:45:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

void	token_list_visualizer(t_all *all)
{
	t_token *first;

	while (all->token->previous != NULL)
		all->token = all->token->previous;
	first = all->token;
	while ()
}