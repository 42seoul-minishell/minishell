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

	bintree = (t_bintree *)malloc(sizeof(t_bintree));
	if (bintree == NULL)
		exit(1);
	bintree->root = NULL;
	return (bintree);
}		

t_bintree_node	*create_bintree_node(t_token *token, t_tnType type)
{		
	t_bintree_node	*node;

	if (token == NULL)
		exit(1);
	node = (t_bintree_node *)malloc(sizeof(t_bintree_node));
	if (node == NULL)
		exit(1);
	node->type = type;
	node->token = token;
	node->lc = NULL;
	node->rc = NULL;
	return (node);
}		
