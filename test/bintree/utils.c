/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:23:20 by bolee             #+#    #+#             */
/*   Updated: 2022/11/17 20:28:09 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bintree.h"

void init_token(t_token *token, t_tnType type, char *value)
{
	token->type = type;
	token->value = value;
}

void init_bintree_node(t_bintree_node *node, int id)
{
	node->id = id;
	node->token = NULL;
	node->lc = NULL;
	node->rc = NULL;
}

void init_bintree(t_bintree *bintree)
{
	bintree->root = NULL;
}

t_tnType check_type(t_tnType type)
{
	if (type == T_NULL)
		return (T_NULL);
	else if (type == T_WORD)
		return (T_WORD);
	else if (type == T_PIPE)
		return (T_PIPE);
	else if (type == T_REDIRECT)
		return (T_REDIRECT);
	else if (type == T_DOUBLE_QUOTES)
		return (T_DOUBLE_QUOTES);
	else
		return (0);
}

t_token *create_token(t_tnType type, char *value)
{
	t_token *new;

	new = malloc(sizeof(t_token));
	if (!new)
		exit(1);
	if (check_type(type) == FALSE)
		exit(1);
	new->type = type;
	new->value = value;
	return (new);
}
