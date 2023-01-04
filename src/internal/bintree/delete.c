/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:16:46 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:16:46 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	_delete_bintree_node(t_bintree_node *node)
{
	t_list	*lst;
	t_list	*tmp;
	t_token	*token;

	lst = node->token_lst;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		token = (t_token *)tmp->content;
		free(token->value);
		free(token);
		free(tmp);
	}
	free(node);
}

void	clear_bintree(t_bintree_node *root)
{
	if (root == NULL)
		return ;
	clear_bintree(root->lc);
	clear_bintree(root->rc);
	_delete_bintree_node(root);
}
