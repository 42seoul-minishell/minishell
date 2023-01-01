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

static void _upper_priority(t_doubly_node *node, t_tnType bt_type)
{
	t_bintree_node *bt_node;
	t_token *token;

	token = create_token(node->token->type, ft_strdup(node->token->value));
	bt_node = create_bintree_node(token, bt_type);
	bt_node->lc = g_global.tree->root;
	g_global.tree->root = bt_node;
}

static void _lower_priority_sub(t_doubly_node *node, t_tnType bt_type)
{
	int flag;
	t_bintree_node *tmp;
	t_token *token;

	tmp = g_global.tree->root;
	flag = 0;
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
	{
		token = create_token(node->token->type, ft_strdup(node->token->value));
		tmp->rc = create_bintree_node(token, bt_type);
	}
}

static void _lower_priority(t_doubly_node *node, t_tnType bt_type)
{
	t_bintree_node *tmp;
	t_token *token;

	if (bt_type >= TN_OR && bt_type <= TN_RDIR)
	{
		token = create_token(node->token->type, ft_strdup(node->token->value));
		tmp = create_bintree_node(token, bt_type);
		tmp->lc = g_global.tree->root->rc;
		g_global.tree->root->rc = tmp;
	}
	else
		_lower_priority_sub(node, bt_type);
}

static void _set_bintree_case(t_doubly_node *node, t_tnType bt_type)
{
	t_token *token;

	if ((g_global.tree->root->type == TN_HEREDOC || g_global.tree->root->type == TN_RDIR) &&
		node->token->type >= CMD && node->token->type <= OPTION &&
		node->prev->token->type >= INP_RDIR && node->prev->token->type <= HERE_DOC)
	{
		token = create_token(node->token->type, ft_strdup(node->token->value));
		ft_lstadd_back(&(g_global.tree->root->token_lst),
					   ft_lstnew((void *)token));
	}
	else if (g_global.tree->root->type > bt_type ||
			 (bt_type >= TN_OR && bt_type <= TN_PIPE))
		_upper_priority(node, bt_type);
	else if (g_global.tree->root->type < bt_type)
		_lower_priority(node, bt_type);
	else
	{
		token = create_token(node->token->type, ft_strdup(node->token->value));
		ft_lstadd_back(&(g_global.tree->root->token_lst),
					   ft_lstnew((void *)token));
	}
}

void set_bintree(t_doubly_list *lst, t_doubly_node *node)
{
	t_tnType bt_type;
	t_token *token;

	if (g_global.tree->root && node == lst->header.next)
		return;
	bt_type = set_bintree_type(node->token->type);
	if (g_global.tree->root == NULL)
	{
		token = create_token(node->token->type, ft_strdup(node->token->value));
		g_global.tree->root = create_bintree_node(token, bt_type);
		set_bintree(lst, node->next);
		return;
	}
	_set_bintree_case(node, bt_type);
	set_bintree(lst, node->next);
}
