/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:19:00 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:19:01 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_doubly_node	*get_node_by_index(t_doubly_list *lst, size_t idx)
{
	size_t			count;
	t_doubly_node	*node;

	if (!lst || is_list_empty(lst) || lst->len <= idx)
		exit(1);
	count = -1;
	node = lst->header.next;
	while (++count < idx)
		node = node->next;
	return (node);
}
