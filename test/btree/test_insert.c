#include "test_btree.h"

int test_insert_lc_node_null(void)
{
	int res;
	t_token token;

	init_token(&token, 1, "TEST");
	res = insert_lc_node(NULL, &token);
	return res;
}

int test_insert_lc_node(void)
{
	int res;
	t_token token;
	t_btree_node bnode;

	init_token(&token, 1, "TEST");
	init_btree_node(&bnode, 1);
	res = insert_lc_node(&bnode, &token);
	free(bnode.lc);
	return res;
}

int test_insert_rc_node_null(void)
{
	int res;
	t_token token;

	init_token(&token, 1, "TEST");
	res = insert_lc_node(NULL, &token);
	return res;
}

int test_insert_rc_node(void)
{
	int res;
	t_token token;
	t_btree_node bnode;

	init_token(&token, 1, "TEST");
	init_btree_node(&bnode, 1);
	res = insert_rc_node(&bnode, &token);
	free(bnode.rc);
	return res;
}
