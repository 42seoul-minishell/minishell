/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:18:43 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:18:44 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token(t_tType type, char *value)
{
	t_token	*new;

	new = (t_token *)sp_malloc(sizeof(t_token));
	new->type = type;
	new->value = value;
	return (new);
}

t_doubly_list	*create_doubly_list(void)
{
	t_doubly_list	*lst;

	lst = (t_doubly_list *)sp_malloc(sizeof(t_doubly_list));
	lst->len = 0;
	return (lst);
}

t_doubly_node	*create_doubly_node(t_token *token)
{
	t_doubly_node	*new;

	new = (t_doubly_node *)sp_malloc(sizeof(t_doubly_node));
	new->token = token;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
