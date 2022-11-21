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
		return;
	}
	else if (node->lc == NULL && node->rc == NULL)
	{
		printf("NODE doesn't have child node\n");
		return;
	}
	else if (node->lc == NULL)
	{
		printf("(Empty) %s\n", node->rc->token->value);
		return;
	}
	else if (node->rc == NULL)
	{
		printf("%s (Empty)\n", node->lc->token->value);
		return;
	}
	printf("%s %s\n", node->lc->token->value, node->rc->token->value);
}

/*
	postorder(전위 순회)

				1
		2				3
	4		5		6		7

	=> 1 2 4 5 3 6 7
*/
void	display_bintree_node_by_preorder(t_bintree_node *node)
{
	if (node == NULL)
		return;
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

/*
	inorder(중위 순회)

				1
		2				3
	4		5		6		7

	=> 4 2 5 1 6 3 7
*/
void	display_bintree_node_by_inorder(t_bintree_node *node)
{
	if (node == NULL)
		return;
	display_bintree_node_by_inorder(node->lc);
	printf("%s ", node->token->value);
	display_bintree_node_by_inorder(node->rc);
}

void	display_bintree_by_inorder(t_bintree *bintree)
{
	printf("\ninorder start\n");
	display_bintree_node_by_inorder(bintree->root);
	printf("\ninorder end\n");
}

/*
	postorder(후위 순회)

				1
		2				3
	4		5		6		7

	=> 4 5 2 6 7 3 1
*/
void	display_bintree_node_by_postorder(t_bintree_node *node)
{
	if (node == NULL)
		return;
	display_bintree_node_by_postorder(node->lc);
	display_bintree_node_by_postorder(node->rc);
	printf("%s ", node->token->value);
}

void	display_bintree_by_postorder(t_bintree *bintree)
{
	printf("\npostorder start\n");
	display_bintree_node_by_postorder(bintree->root);
	printf("\npostorder end\n");
}
