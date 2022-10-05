#include "test_doublylist.h"

void	init_token(t_token *token, t_type type, char *value)
{
	token->type = type;
	token->value = value;
}

void	init_node(t_doubly_node *node, t_token *token)
{
	node->token = token;
	node->next = NULL;
	node->prev = NULL;
}

void	init_lst(t_doubly_list *lst)
{
	t_token			token;
	t_doubly_node	header;

	init_token(&token, 0, "DUMMY");
	init_node(&header, &token);

	lst->header = header;
	lst->len = 0;
}