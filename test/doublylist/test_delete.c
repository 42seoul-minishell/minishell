#include "test_doublylist.h"

int test_find_delete_and_release_list(char *str)
{
	t_token *token[3];
	t_doubly_node *node[3];
	t_doubly_list *lst;
	t_doubly_node *tmp_node;
	char **tmp_str;
	int tmp;

	tmp_str = (char **)malloc(sizeof(char *) * 3);
	for (int i = 0; i < 3; i++)
	{
		tmp_str[i] = (char *)malloc(sizeof(char) * 10);
		if (!tmp_str[i])
			return (FALSE);
	}

	strcpy(tmp_str[0], "TEST00");
	strcpy(tmp_str[1], "TEST01");
	strcpy(tmp_str[2], "TEST02");

	lst = create_doubly_list();
	if (!lst)
		return (FALSE);

	for (int i = 0; i < 3; i++)
	{
		token[i] = create_token(i + 1, tmp_str[i]);
		if (!token[i])
			return (FALSE);
	}

	for (int i = 0; i < 3; i++)
	{
		node[i] = create_doubly_node(token[i]);
		if (!node[i])
			return (FALSE);
	}

	tmp = insert_node(lst, node[0]);
	if (tmp == FALSE)
		return (FALSE);
	tmp = insert_node(lst, node[1]);
	if (tmp == FALSE)
		return (FALSE);
	tmp = insert_node(lst, node[2]);
	if (tmp == FALSE)
		return (FALSE);

	find_delete_doubly_node(lst, str);
	tmp_node = find_doubly_node(lst, str);
	if (tmp_node == NULL)
	{
		release_doubly_list(lst);
		free(tmp_str);
		return (TRUE);
	}
	release_doubly_list(lst);
	free(tmp_str);
	return (FALSE);
}
