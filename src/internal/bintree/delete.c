/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:11:18 by bolee             #+#    #+#             */
/*   Updated: 2022/11/16 15:11:19 by bolee            ###   ########.fr       */
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
