/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:26:37 by mingkim           #+#    #+#             */
/*   Updated: 2022/10/07 13:43:42 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"


int	insert_node(t_doubly_list *lst, t_doubly_node *node)
{
	if (!lst || !node)
		return (FALSE);
	if (lst->len)
	{
		node->prev = lst->header.prev;
		node->next = lst->header.next;
		lst->header.prev->next = node;
		lst->header.next->prev = node;
	}
	else
	{
		lst->header.next = node;
		node->next = node;
		node->prev = node;
	}
	lst->header.prev = node;
	lst->len++;
	return (TRUE);
}

int	insert_node_by_index(t_doubly_list *lst, t_doubly_node *node, size_t index)
{
	t_doubly_node	*buf;
	size_t			count;

	if (!lst || lst->len < index)
		return (FALSE);
	if (is_list_empty(lst) || index == lst->len || !index)
		return (insert_node(lst, node));
	buf = &lst->header;
	count = -1;
	while (++count < index)
		buf = buf->next;
	node->prev = buf->prev;
	node->next = buf;
	lst->len++;
	return (TRUE);
}
