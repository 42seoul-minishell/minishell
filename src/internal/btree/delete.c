#include "../../../include/minishell.h"

void delete_btree_node_child(t_btree_node *parent)
{
	if (parent == NULL)
		return;
	delete_btree_node_child(parent->lc);
	delete_btree_node_child(parent->rc);
	free(parent->token->value);
	free(parent->token);
	free(parent);
}

int delete_btree_node_lc(t_btree_node *parent)
{
	if (parent == NULL)
		return (FALSE);
	if (parent->lc == NULL)
		return (FALSE);
	delete_btree_node_child(parent->lc);
	parent->lc = NULL;
	return (TRUE);
}

int delete_btree_node_rc(t_btree_node *parent)
{
	if (parent == NULL)
		return (FALSE);
	if (parent->rc == NULL)
		return (FALSE);
	delete_btree_node_child(parent->rc);
	parent->rc = NULL;
	return (TRUE);
}
