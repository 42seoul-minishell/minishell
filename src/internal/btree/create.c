#include "../../../include/minishell.h"

t_btree	*create_btree()
{
	t_btree	*btree;

	btree = (t_btree *)malloc(sizeof(t_btree));
	if (btree == NULL)
		return (NULL);
	btree->root = NULL;
	return (btree);
}

t_btree_node	*create_node(t_token *token)
{
	t_btree_node	*node;

	node = (t_btree_node *)malloc(sizeof(t_btree_node));
	if (node == NULL)
		return (NULL);
	node->id = -1;
	node->token = token;
	node->lc = NULL;
	node->rc = NULL;
	return (node);
}
