/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:48:30 by gimmingyu         #+#    #+#             */
/*   Updated: 2022/10/31 10:48:53 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_btree_node	*get_btree_node_by_id(t_btree_node *node, int id)
{
	if (node == NULL)
		return (NULL);
	if (id == node->id)
		return (node);
	else if (id < node->id)
		return (get_btree_node_by_id(node->lc, id));
	else
		return (get_btree_node_by_id(node->rc, id));
}
