/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:10:59 by bolee             #+#    #+#             */
/*   Updated: 2022/11/17 20:28:09 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

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

	if (token == NULL)
		exit(1);
	node = (t_bintree_node *)sp_malloc(sizeof(t_bintree_node));
	node->type = type;
	node->token = token;
	node->lc = NULL;
	node->rc = NULL;
	return (node);
}
