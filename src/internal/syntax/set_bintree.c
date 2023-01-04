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

static void	_upper_priority(t_list *token_list, t_tnType bt_type)
{
	t_bintree_node	*bt_node;

	bt_node = create_bintree_node(token_list, bt_type);
	bt_node->lc = g_global.tree->root;
	g_global.tree->root = bt_node;
}

static void	_lower_priority(t_list *token_list, t_tnType bt_type)
{
	int				flag;
	t_bintree_node	*bt_node;
	t_bintree_node	*tmp;

	flag = 0;
	bt_node = create_bintree_node(token_list, bt_type);
	if (bt_type >= TN_OR && bt_type <= TN_PIPE)
		flag = 1;
	if (g_global.tree->root->type < bt_type && flag)
	{
		bt_node->lc = g_global.tree->root->rc;
		g_global.tree->root->rc = bt_node;
	}
	else if (g_global.tree->root->type < bt_type)
	{
		tmp = g_global.tree->root;
		while (tmp->rc)
			tmp = tmp->rc;
		tmp->rc = bt_node;
	}
}

static void	_check_priority(t_doubly_list *lst, t_doubly_node **node)
{
	t_tnType	bt_type;
	t_list		*token_list;

	token_list = set_token_list(lst, node);
	relocate_token_list(&token_list);
	bt_type = check_ctrl_oper(token_list);
	if (bt_type == TN_NONE)
		bt_type = set_bintree_type(token_list);
	if (g_global.tree->root->type >= bt_type)
		_upper_priority(token_list, bt_type);
	else
		_lower_priority(token_list, bt_type);
}

void	set_bintree(t_doubly_list *lst, t_doubly_node *node)
{
	t_tnType	bt_type;
	t_list		*token_list;

	if (g_global.tree->root && node == lst->header.next)
		return ;
	if (g_global.tree->root == NULL)
	{
		token_list = set_token_list(lst, &node);
		relocate_token_list(&token_list);
		bt_type = check_ctrl_oper(token_list);
		if (bt_type == TN_NONE)
			bt_type = set_bintree_type(token_list);
		g_global.tree->root = create_bintree_node(token_list, bt_type);
		set_bintree(lst, node);
		return ;
	}
	_check_priority(lst, &node);
	set_bintree(lst, node);
}
