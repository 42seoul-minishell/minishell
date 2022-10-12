#include "test_doublylist.h"

int test_get_node_by_index(size_t index)
{
	t_token token[3];
	t_doubly_node node[3];
	t_doubly_list lst;
	t_doubly_node *tmp_node;
	int tmp;

	init_lst(&lst);
	tmp_node = &(lst.header);
	init_token(&token[0], 1, "TEST00");
	init_node(&node[0], &token[0]);
	tmp = insert_node(&lst, &node[0]);
	if (tmp == FALSE)
		return (FALSE);

	init_token(&token[1], 2, "TEST01");
	init_node(&node[1], &token[1]);
	tmp = insert_node(&lst, &node[1]);
	if (tmp == FALSE)
		return (FALSE);

	init_token(&token[2], 3, "TEST02");
	init_node(&node[2], &token[2]);
	tmp = insert_node(&lst, &node[2]);
	if (tmp == FALSE)
		return (FALSE);

	tmp_node = get_node_by_index(&lst, index);
	if (tmp_node == NULL)
		return (FALSE);

	if ((index == 0 && tmp_node == &node[0]) ||
		(index == 1 && tmp_node == &node[1]) ||
		(index == 2 && tmp_node == &node[2]))
		return (TRUE);

	return (FALSE);
}

int test_get_node_by_index_null(size_t index)
{
	t_doubly_node *node;

	node = get_node_by_index(NULL, index);
	if (node == NULL)
		return (FALSE);
	return (TRUE);
}

int test_get_node_by_index_empty(size_t index)
{
	t_doubly_list lst;
	t_doubly_node *node;

	init_lst(&lst);
	node = get_node_by_index(&lst, index);
	if (node == NULL)
		return (FALSE);
	return (TRUE);
}
