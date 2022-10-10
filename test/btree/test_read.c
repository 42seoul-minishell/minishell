#include "test_btree.h"

int test_get_btree_node_by_id_null(int id)
{
	t_btree_node *res_node;

	res_node = get_btree_node_by_id(NULL, id);
	if (!res_node)
		return (TRUE);
	return (FALSE);
}

int test_get_btree_node_by_id(int id)
{
	// 트리 생성
	/*
			  5
		  2		  7
		1	4	6	8
			3
	*/
	t_btree_node node[8];
	t_btree_node *res_node;

	for (int i = 0; i < 8; i++)
		init_btree_node(&node[i], i + 1);

	node[4].lc = &node[1];
	node[4].rc = &node[6];

	node[1].lc = &node[0];
	node[1].rc = &node[3];

	node[3].lc = &node[2];

	node[6].lc = &node[5];
	node[6].rc = &node[7];

	res_node = get_btree_node_by_id(&node[4], id);
	if (!res_node)
		return (FALSE);
	if (res_node->id != node[id - 1].id)
		return (FALSE);
	return (TRUE);
}
