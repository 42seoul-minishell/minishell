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

void print_token_lst(t_list *token_lst)
{
	t_token *content;

	while (token_lst)
	{
		content = token_lst->content;
		printf("%s ", content->value);
		token_lst = token_lst->next;
	}
}

void display_bintree_node_child(t_bintree_node *node)
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

static void _display_bintree_node_by_2D(t_bintree_node *root, int space, int count)
{
	if (root == NULL)
		return;
	space += count;
	_display_bintree_node_by_2D(root->rc, space, count);
	printf("\n");
	for (int i = count; i < space; i++)
		printf(" ");
	printf("%d ", root->type);
	print_token_lst(root->token_lst);
	_display_bintree_node_by_2D(root->lc, space, count);
}

void display_bintree_by_2D(t_bintree *bintree)
{
	printf("\nStart print bintree\n");
	_display_bintree_node_by_2D(bintree->root, 0, 10);
	printf("\n\nEnd print bintree\n");
}
