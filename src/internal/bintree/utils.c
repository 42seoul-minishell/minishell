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

void	print_token_lst(t_list *token_lst)
{
	t_token	*content;

	while (token_lst)
	{
		content = token_lst->content;
		printf("%s ", content->value);
		token_lst = token_lst->next;
	}
}

void	display_bintree_node_child(t_bintree_node *node)
{
	if (node == NULL)
		printf("There is no NODE\n");
	else if (node->lc == NULL && node->rc == NULL)
		printf("NODE doesn't have child node\n");
	else if (node->lc == NULL)
	{
		printf("(Empty)");
		print_token_lst(node->rc->token_lst);
	}
	else if (node->rc == NULL)
	{
		print_token_lst(node->lc->token_lst);
	}
	else
	{
		print_token_lst(node->lc->token_lst);
		print_token_lst(node->rc->token_lst);
		printf("\n");
	}
}

void	display_bintree_node_by_inorder(t_bintree_node *node)
{
	if (node == NULL)
		return ;
	display_bintree_node_by_inorder(node->lc);
	print_token_lst(node->token_lst);
	printf("$\n");
	display_bintree_node_by_inorder(node->rc);
}

void	display_bintree_by_inorder(t_bintree *bintree)
{
	printf("\ninorder start\n");
	display_bintree_node_by_inorder(bintree->root);
	printf("\ninorder end\n");
}
