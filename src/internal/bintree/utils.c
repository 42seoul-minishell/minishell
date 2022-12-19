/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:12:38 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:17:05 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_bintree_node_child(t_bintree_node *node)
{
	if (node == NULL)
	{
		printf("There is no NODE\n");
		return ;
	}
	else if (node->lc == NULL && node->rc == NULL)
	{
		printf("NODE doesn't have child node\n");
		return ;
	}
	else if (node->lc == NULL)
	{
		printf("(Empty) %s\n", node->rc->token->value);
		return ;
	}
	else if (node->rc == NULL)
	{
		printf("%s (Empty)\n", node->lc->token->value);
		return ;
	}
	printf("%s %s\n", node->lc->token->value, node->rc->token->value);
}

void	display_bintree_node_by_inorder(t_bintree_node *node)
{
	if (node == NULL)
		return ;
	display_bintree_node_by_inorder(node->lc);
	printf("%s$ ", node->token->value);
	display_bintree_node_by_inorder(node->rc);
}

void	display_bintree_by_inorder(t_bintree *bintree)
{
	printf("\ninorder start\n");
	display_bintree_node_by_inorder(bintree->root);
	printf("\ninorder end\n");
}
