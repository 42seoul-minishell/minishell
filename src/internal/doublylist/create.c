/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:23:51 by mingkim           #+#    #+#             */
/*   Updated: 2022/10/14 15:34:15 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_token	*create_token(t_type type, char *value)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	if (check_type(type) == FALSE)
		return (NULL);
	new->type = type;
	new->value = value;
	return (new);
}

t_doubly_list	*create_doubly_list(void)
{
	t_doubly_list	*lst;

	lst = malloc(sizeof(t_doubly_list));
	if (!lst)
		return (NULL);
	lst->len = 0;
	return (lst);
}

t_doubly_node	*create_doubly_node(t_token *token)
{
	t_doubly_node	*new;

	new = malloc(sizeof(t_doubly_node));
	if (!new)
		return (NULL);
	new->token = token;
	return (new);
}
