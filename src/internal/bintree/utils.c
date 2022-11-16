/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:12:38 by bolee             #+#    #+#             */
/*   Updated: 2022/11/16 15:12:39 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

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

void	display_bintree_node_by_preorder(t_bintree_node *node)
{
	if (node == NULL)
		return ;
	printf("%s ", node->token->value);
	display_bintree_node_by_preorder(node->lc);
	display_bintree_node_by_preorder(node->rc);
}

void	display_bintree_by_preorder(t_bintree *bintree)
{
	printf("\npreorder start\n");
	display_bintree_node_by_preorder(bintree->root);
	printf("\npreorder end\n");
}
