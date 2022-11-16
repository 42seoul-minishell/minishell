/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:23:06 by bolee             #+#    #+#             */
/*   Updated: 2022/11/16 15:23:07 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bintree.h"

int test_delete_bintree_node_lc_null_node(void)
{
	int res;

	res = delete_bintree_node_lc(NULL);
	return res;
}

int test_delete_bintree_node_lc_null(void)
{
	int res;
	t_bintree_node node;

	init_bintree_node(&node, 1);
	res = delete_bintree_node_lc(&node);
	return res;
}

int test_delete_bintree_node_lc(void)
{
	int res;
	char *str[2];
	t_token *token[2];
	t_bintree_node *node[2];
	t_bintree_node *tmp;

	str[0] = (char *)malloc(sizeof(char) * 10);
	if (!str[0])
		return FALSE;
	str[1] = (char *)malloc(sizeof(char) * 10);
	if (!str[1])
		return FALSE;

	strcpy(str[0], "TEST00");
	strcpy(str[1], "TEST01");

	token[0] = create_token(1, str[0]);
	token[1] = create_token(2, str[1]);

	node[0] = create_bintree_node(token[0]);
	node[1] = create_bintree_node(token[1]);

	node[0]->id = 2;
	node[1]->id = 1;

	node[0]->lc = node[1];
	res = delete_bintree_node_lc(node[0]);
	tmp = get_bintree_node_by_id(node[0], 1);

	free(node[0]->token->value);
	free(node[0]->token);
	free(node[0]);

	if (res == TRUE && tmp == NULL)
		return TRUE;

	return FALSE;
}

int test_delete_bintree_node_rc_null_node(void)
{
	int res;

	res = delete_bintree_node_rc(NULL);
	return res;
}

int test_delete_bintree_node_rc_null(void)
{
	int res;
	t_bintree_node node;

	init_bintree_node(&node, 1);
	res = delete_bintree_node_lc(&node);
	return res;
}

int test_delete_bintree_node_rc(void)
{
	int res;
	char *str[2];
	t_token *token[2];
	t_bintree_node *node[2];
	t_bintree_node *tmp;

	str[0] = (char *)malloc(sizeof(char) * 10);
	if (!str[0])
		return FALSE;
	str[1] = (char *)malloc(sizeof(char) * 10);
	if (!str[1])
		return FALSE;

	strcpy(str[0], "TEST00");
	strcpy(str[1], "TEST01");

	token[0] = create_token(1, str[0]);
	token[1] = create_token(2, str[1]);

	node[0] = create_bintree_node(token[0]);
	node[1] = create_bintree_node(token[1]);

	node[0]->id = 2;
	node[1]->id = 1;

	node[0]->rc = node[1];
	res = delete_bintree_node_rc(node[0]);
	tmp = get_bintree_node_by_id(node[0], 1);

	free(node[0]->token->value);
	free(node[0]->token);
	free(node[0]);

	if (res == TRUE && tmp == NULL)
		return TRUE;
	return FALSE;
}

void test_delete_bintree_node_chlid(void)
{
	char *str[3];
	t_token *token[3];
	t_bintree_node *node[3];

	str[0] = (char *)malloc(sizeof(char) * 10);
	str[1] = (char *)malloc(sizeof(char) * 10);
	str[2] = (char *)malloc(sizeof(char) * 10);

	strcpy(str[0], "TEST00");
	strcpy(str[1], "TEST01");
	strcpy(str[2], "TEST02");

	token[0] = create_token(1, str[0]);
	token[1] = create_token(2, str[1]);
	token[2] = create_token(3, str[2]);

	node[0] = create_bintree_node(token[0]);
	node[1] = create_bintree_node(token[1]);
	node[2] = create_bintree_node(token[2]);

	node[0]->id = 3;
	node[1]->id = 1;
	node[2]->id = 2;

	node[0]->lc = node[1];
	node[0]->rc = node[2];

	delete_bintree_node_child(node[0]);
}
