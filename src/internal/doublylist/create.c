/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:23:51 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/17 20:25:35 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

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
	return (new);
}
