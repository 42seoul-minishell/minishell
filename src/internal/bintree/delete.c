/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:11:18 by bolee             #+#    #+#             */
/*   Updated: 2022/11/16 17:28:21 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	delete_bintree_node_child(t_bintree_node *parent)
{
	if (parent == NULL)
		return ;
	delete_bintree_node_child(parent->lc);
	delete_bintree_node_child(parent->rc);
	free(parent->token->value);
	free(parent->token);
	free(parent);
}

int	delete_bintree_node_lc(t_bintree_node *parent)
{
	if (parent == NULL)
		return (FALSE);
	if (parent->lc == NULL)
		return (FALSE);
	delete_bintree_node_child(parent->lc);
	parent->lc = NULL;
	return (TRUE);
}

int	delete_bintree_node_rc(t_bintree_node *parent)
{
	if (parent == NULL)
		return (FALSE);
	if (parent->rc == NULL)
		return (FALSE);
	delete_bintree_node_child(parent->rc);
	parent->rc = NULL;
	return (TRUE);
}

int	clear_bintree_node(t_bintree_node *root)
{
	t_bintree_node	*next;

	if (root->lc)
		clear_bintree_node(root->lc);
	if (root->rc)
		clear_bintree_node(root->rc);
	free(root);
	return (TRUE);
}
