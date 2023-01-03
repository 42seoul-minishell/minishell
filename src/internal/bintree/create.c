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

	bintree = (t_bintree *)ft_malloc(sizeof(t_bintree));
	bintree->root = NULL;
	return (bintree);
}

t_bintree_node	*create_bintree_node(t_list *token_list, t_tnType type)
{
	t_bintree_node	*node;

	node = (t_bintree_node *)ft_malloc(sizeof(t_bintree_node));
	node->type = type;
	node->token_lst = token_list;
	node->fd[0] = 0;
	node->fd[1] = 1;
	node->lc = NULL;
	node->rc = NULL;
	return (node);
}
