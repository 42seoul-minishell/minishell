/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:16:56 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:16:57 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	insert_lc_node(t_bintree_node *parent, t_list *token_list, t_tnType type)
{
	t_bintree_node	*node;

	if (parent == NULL || token_list == NULL)
		return (FALSE);
	node = create_bintree_node(token_list, type);
	if (node == NULL)
		return (FALSE);
	parent->lc = node;
	return (TRUE);
}

int	insert_rc_node(t_bintree_node *parent, t_list *token_list, t_tnType type)
{
	t_bintree_node	*node;

	if (parent == NULL || token_list == NULL)
		return (FALSE);
	node = create_bintree_node(token_list, type);
	if (node == NULL)
		return (FALSE);
	parent->rc = node;
	return (TRUE);
}
