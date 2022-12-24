/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bintree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:26:19 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:26:20 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int _set_bintree_type(int type)
{
	if (type == OR)
		return (TN_OR);
	else if (type == AND)
		return (TN_AND);
	else if (type == PIPE)
		return (TN_PIPE);
	else if (type >= INP_RDIR && type <= HERE_DOC)
		return (TN_RDIR);
	else if (type == BRACKET)
		return (TN_BRACKET);
	else
		return (TN_WORD);
}

static void _upper_priority(t_doubly_node *node, t_tnType bt_type)
{
	t_bintree_node *bt_node;

	bt_node = create_bintree_node(
		create_token(node->token->type, node->token->value), bt_type);
	bt_node->lc = g_global.tree->root;
	g_global.tree->root = bt_node;
}

static void _lower_priority(t_doubly_node *node, t_tnType bt_type)
{
	int flag;
	t_bintree_node *tmp;

	flag = 0;
	if (bt_type >= TN_OR && bt_type <= TN_RDIR)
	{
		tmp = create_bintree_node(
			create_token(node->token->type, node->token->value), bt_type);
		tmp->lc = g_global.tree->root->rc;
		g_global.tree->root->rc = tmp;
	}
	else
	{
		tmp = g_global.tree->root;
		while (tmp->rc)
		{
			tmp = tmp->rc;
			if (tmp->type == bt_type)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			ft_lstadd_back(&tmp->token_lst, ft_lstnew((void *)node->token));
		else
			tmp->rc = create_bintree_node(
				create_token(node->token->type, node->token->value), bt_type);
	}
}

void set_bintree(t_doubly_list *lst, t_doubly_node *node)
{
	t_tnType bt_type;

	if (g_global.tree->root && node == lst->header.next)
		return;
	bt_type = _set_bintree_type(node->token->type);
	if (g_global.tree->root == NULL)
	{
		g_global.tree->root = create_bintree_node(
			create_token(node->token->type, node->token->value), bt_type);
		set_bintree(lst, node->next);
		return;
	}
	if (g_global.tree->root->type == TN_RDIR && node->token->type >= CMD &&
		node->token->type <= OPTION && node->prev->token->type >= INP_RDIR && node->prev->token->type <= HERE_DOC)
		ft_lstadd_back(&(g_global.tree->root->token_lst), ft_lstnew((void *)node->token));
	else if (g_global.tree->root->type > bt_type || (bt_type >= TN_OR && bt_type <= TN_RDIR))
		_upper_priority(node, bt_type);
	else if (g_global.tree->root->type < bt_type)
		_lower_priority(node, bt_type);
	else
		ft_lstadd_back(&(g_global.tree->root->token_lst), ft_lstnew((void *)node->token));
	set_bintree(lst, node->next);
}
