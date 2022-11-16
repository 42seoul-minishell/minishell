/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:10:59 by bolee             #+#    #+#             */
/*   Updated: 2022/11/16 15:11:01 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"		

t_bintree *create_bintree(void)		
{		
	t_bintree *bintree;		

	bintree = (t_bintree *)malloc(sizeof(t_bintree));		
	if (bintree == NULL)		
		return (NULL);		
	bintree->root = NULL;		
	return (bintree);		
}		

t_bintree_node *create_bintree_node(t_token *token)		
{		
	t_bintree_node *node;		

	if (token == NULL)
		return (NULL);		
	node = (t_bintree_node *)malloc(sizeof(t_bintree_node));		
	if (node == NULL)		
		return (NULL);		
	node->id = -1;		
	node->token = token;		
	node->lc = NULL;		
	node->rc = NULL;		
	return (node);		
}		
