#include "test_doublylist.h"

int	test_insert_node_empty(t_type type, char *value)
{
	t_token			token;
	t_doubly_node	node;
	t_doubly_list	lst;
	int				tmp;

	init_token(&token, type, value);
	init_node(&node, &token);
	init_lst(&lst);

	tmp = insert_node(&lst, &node);
	if (tmp == FALSE || \
		lst.header.next != &node || \
		lst.len != 1)
		return (FALSE);
	return (TRUE);
}

int test_insert_node(t_type type, char *value)
{
	t_token			token[3];
	t_doubly_node	node[3];
	t_doubly_list	lst;
	int				tmp;
	t_doubly_node	*tmp_node;

	init_lst(&lst);
	tmp_node = &(lst.header);
	init_token(&token[0], 0, "TEST00");
	init_node(&node[0], &token[0]);
	tmp = insert_node(&lst, &node[0]);
	if (tmp == FALSE)
		return (FALSE);
	tmp_node = tmp_node->next; // node[0]

	init_token(&token[1], 1, "TEST01");
	init_node(&node[1], &token[1]);
	tmp = insert_node(&lst, &node[1]);
	if (tmp == FALSE)
		return (FALSE);
	tmp_node = tmp_node->next; // node[1]

	init_token(&token[2], type, value);
	init_node(&node[2], &token[2]);
	tmp = insert_node(&lst, &node[2]);
	if (tmp == FALSE)
		return (FALSE);
	tmp_node = tmp_node->next; // node[2]
	if (tmp_node != &node[2] || \
		lst.len != 3)
		return (FALSE);
	return (TRUE);
}

int	test_insert_node_lst_null(void)
{
	t_token			token;
	t_doubly_node	node;
	int				tmp;

	init_token(&token, 0, "TEST");
	init_node(&node, &token);

	tmp = insert_node(NULL, &node);
	if (tmp == FALSE)
		return (TRUE);
	return (FALSE);
}

int	test_insert_node_node_null(void)
{
	t_doubly_list	lst;
	int				tmp;

	init_lst(&lst);

	tmp = insert_node(&lst, NULL);
	if (tmp == FALSE)
		return (TRUE);
	return (FALSE);
}

int test_insert_node_by_index_empty(t_type type, char *value, size_t index)
{
	t_token			token;
	t_doubly_node	node;
	t_doubly_list	lst;
	int				tmp;

	init_token(&token, type, value);
	init_node(&node, &token);
	init_lst(&lst);
	tmp = insert_node_by_index(&lst, &node, index);
	if (tmp == FALSE || \
		lst.header.next != &node || \
		lst.len != 1)
		return (FALSE);
	return (TRUE);
}

int test_insert_node_by_index(t_type type, char *value, size_t index)
{
	t_token			token[3];
	t_doubly_node	node[3];
	t_doubly_list	lst;
	int				tmp;
	t_doubly_node	*tmp_node;
	size_t			count;

	init_lst(&lst);
	tmp_node = &(lst.header);
	init_token(&token[0], 0, "TEST00");
	init_node(&node[0], &token[0]);
	tmp = insert_node_by_index(&lst, &node[0], 0);
	if (tmp == FALSE)
		return (FALSE);

	init_token(&token[1], 1, "TEST01");
	init_node(&node[1], &token[1]);
	tmp = insert_node_by_index(&lst, &node[1], 1);
	if (tmp == FALSE)
		return (FALSE);

	init_token(&token[2], type, value);
	init_node(&node[2], &token[2]);
	tmp = insert_node_by_index(&lst, &node[2], 2);
	if (tmp == FALSE)
		return (FALSE);

	if (lst.len != 3)
		return (FALSE);

	if (index > lst.len - 1)
	{
		tmp_node = tmp_node->next;
		if (tmp_node != node)
			return (FALSE);
		return (TRUE);
	}

	tmp_node = &(lst.header);
	count = -1;
	while (++count < index)
		tmp_node = tmp_node->next;
	if (tmp_node != node)
		return (FALSE);
	return (TRUE);
}
