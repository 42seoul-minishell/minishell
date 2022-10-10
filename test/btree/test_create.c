#include "test_btree.h"

int test_create_btree(void)
{
	t_btree *btree;

	btree = create_btree();
	if (btree == NULL)
		return (FALSE);
	free(btree);
	return (TRUE);
}

int test_create_btree_node(void)
{
	t_btree_node *node;
	t_token token;

	init_token(&token, 0, "TEST");
	node = create_btree_node(&token);
	if (node == NULL)
		return (FALSE);
	free(node);
	return (TRUE);
}
