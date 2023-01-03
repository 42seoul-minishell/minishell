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

static void	_display_bintree_node_by_2d(t_bintree_node *root, \
											int space, int count)
{
	int	i;

	if (root == NULL)
		return ;
	space += count;
	_display_bintree_node_by_2d(root->rc, space, count);
	printf("\n");
	i = count;
	while (i < space)
	{
		printf(" ");
		i++;
	}
	printf("%d ", root->type);
	print_token_lst(root->token_lst);
	_display_bintree_node_by_2d(root->lc, space, count);
}

void	display_bintree_by_2d(t_bintree *bintree)
{
	printf("\nStart print bintree\n");
	_display_bintree_node_by_2d(bintree->root, 0, 10);
	printf("\n\nEnd print bintree\n");
}
