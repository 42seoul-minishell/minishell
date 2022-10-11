#include "test_btree.h"

void init_token(t_token *token, t_type type, char *value)
{
	token->type = type;
	token->value = value;
}

void init_btree_node(t_btree_node *node, int id)
{
	node->id = id;
	node->token = NULL;
	node->lc = NULL;
	node->rc = NULL;
}

void init_btree(t_btree *btree)
{
	btree->root = NULL;
}

t_token *create_token(t_type type, char *value)
{
	t_token *new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	if (switch_type(type) == FALSE)
		return (NULL);
	new->type = type;
	new->value = value;
	return (new);
}

t_type switch_type(t_type type)
{
	if (type == T_NULL)
		return (T_NULL);
	else if (type == T_WORD)
		return (T_WORD);
	else if (type == T_PIPE)
		return (T_PIPE);
	else if (type == T_REDIRECT)
		return (T_REDIRECT);
	else if (type == T_DOUBLE_QUOTES)
		return (T_DOUBLE_QUOTES);
	else
		return (0);
}