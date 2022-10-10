#include "../../../include/minishell.h"

int insert_lc_node(t_btree_node *parent, t_token *token)
{
	t_btree_node *node;

	if (parent == NULL || token == NULL)
		return (FALSE);
	node = create_btree_node(token);
	if (node == NULL)
		return (FALSE);
	parent->lc = node;
	return (TRUE);
}

int insert_rc_node(t_btree_node *parent, t_token *token)
{
	t_btree_node *node;

	if (parent == NULL || token == NULL)
		return (FALSE);
	node = create_btree_node(token);
	if (node == NULL)
		return (FALSE);
	parent->rc = node;
	return (TRUE);
}
