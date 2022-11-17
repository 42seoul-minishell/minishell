/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:12:19 by bolee             #+#    #+#             */
/*   Updated: 2022/11/17 17:08:21 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	insert_lc_node(t_bintree_node *parent, t_token *token, t_tnType type)
{
	t_bintree_node	*node;

	if (parent == NULL || token == NULL)
		return (FALSE);
	node = create_bintree_node(token, type);
	if (node == NULL)
		return (FALSE);
	parent->lc = node;
	return (TRUE);
}

int	insert_rc_node(t_bintree_node *parent, t_token *token, t_tnType type)
{
	t_bintree_node	*node;

	if (parent == NULL || token == NULL)
		return (FALSE);
	node = create_bintree_node(token. type);
	if (node == NULL)
		return (FALSE);
	parent->rc = node;
	return (TRUE);
}
