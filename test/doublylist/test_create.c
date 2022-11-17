#include "test_doublylist.h"

int	test_create_token(t_tType type, char *value)
{
	t_token	*token;

	token = create_token(type, value);
	if (token == NULL)
		return (FALSE);
	if (token->type != type || \
		strcmp(token->value, value) != 0)
	{
		free(token);
		return (FALSE);
	}
	free(token);
	return (TRUE);
}

int	test_create_doubly_list(void)
{
	t_doubly_list	*lst;

	lst = create_doubly_list();
	if (lst == NULL)
		return (FALSE);
	if (lst->len != 0)
	{
		free(lst);
		return (FALSE);
	}
	free(lst);
	return (TRUE);
}

int	test_create_doubly_node(t_tType type, char *value)
{
	t_token			token;
	t_doubly_node	*node;

	init_token(&token, type, value);
	node = create_doubly_node(&token);
	if (node == NULL)
		return (FALSE);
	if (node->token != &token)
	{
		free(node);
		return (FALSE);
	}
	free(node);
	return (TRUE);
}
