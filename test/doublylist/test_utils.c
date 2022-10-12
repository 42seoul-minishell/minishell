#include "test_doublylist.h"

int test_is_list_empty(void)
{
	t_doubly_list lst;
	int tmp;

	init_lst(&lst);
	tmp = is_list_empty(&lst);
	if (tmp == FALSE)
		return (FALSE);
	return (TRUE);
}

int test_is_not_list_empty(void)
{
	t_token token;
	t_doubly_node node;
	t_doubly_list lst;
	t_doubly_node *tmp_node;
	int tmp;

	init_lst(&lst);
	tmp_node = &(lst.header);
	init_token(&token, 0, "TEST00");
	init_node(&node, &token);
	tmp_node->next = &node;
	node.prev = tmp_node;
	lst.len++;
	tmp = is_list_empty(&lst);
	if (tmp == FALSE)
		return (TRUE);
	return (FALSE);
}

int test_find_doubly_node_empty(char *str)
{
	t_doubly_list lst;
	t_doubly_node *tmp_node;

	init_lst(&lst);
	tmp_node = find_doubly_node(&lst, str);
	if (tmp_node == NULL)
		return (TRUE);
	return (FALSE);
}

int test_find_doubly_node(char *str)
{
	t_token token[3];
	t_doubly_node node[3];
	t_doubly_list lst;
	t_doubly_node *tmp_node;

	init_lst(&lst);
	tmp_node = &(lst.header);
	init_token(&token[0], 1, "TEST00");
	init_node(&node[0], &token[0]);
	insert_node(&lst, &node[0]);
	init_token(&token[1], 2, "TEST01");
	init_node(&node[1], &token[1]);
	insert_node(&lst, &node[1]);
	init_token(&token[2], 3, "TEST02");
	init_node(&node[2], &token[2]);
	insert_node(&lst, &node[2]);

	tmp_node = find_doubly_node(&lst, str);
	if (tmp_node == NULL)
		return (FALSE);
	return (TRUE);
}
