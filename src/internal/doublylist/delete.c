/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:42:45 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/17 17:03:50 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	delete_doubly_node(t_doubly_list *lst, t_doubly_node *node)
{
	if (lst->header.next == node)
	{
		lst->header.next = node->next;
		lst->header.prev->next = node->next;
	}
	else if (lst->header.prev == node)
	{
		lst->header.prev = node->prev;
		lst->header.prev->next = node->next;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	free(node->token->value);
	free(node->token);
	free(node);
	lst->len--;
}

void	find_delete_doubly_node(t_doubly_list *lst, char *str)
{
	t_doubly_node	*node;

	node = find_doubly_node(lst, str);
	if (node == NULL)
		return ;
	delete_doubly_node(lst, node);
}

void	release_doubly_list(t_doubly_list *lst)
{
	t_doubly_node	*node;
	t_doubly_node	*tmp;

	if (is_list_empty(lst))
		return ;
	node = lst->header.next;
	while (is_list_empty(lst) == FALSE)
	{
		tmp = node->next;
		delete_doubly_node(lst, node);
		node = tmp;
	}
	free(lst);
}
