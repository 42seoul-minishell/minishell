/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:16:40 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:16:41 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bintree	*create_bintree(void)
{
	t_bintree	*bintree;

	bintree = (t_bintree *)sp_malloc(sizeof(t_bintree));
	bintree->root = NULL;
	return (bintree);
}

t_bintree_node	*create_bintree_node(t_token *token, t_tnType type)
{
	t_bintree_node	*node;

	node = (t_bintree_node *)sp_malloc(sizeof(t_bintree_node));
	node->type = type;
	node->token_lst = NULL;
	ft_lstadd_back(&node->token_lst, ft_lstnew((void *) token));
	node->lc = NULL;
	node->rc = NULL;
	return (node);
}
