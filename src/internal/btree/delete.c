#include "../../../include/minishell.h"

void	delete_child(t_btree_node *parent)
{
	if (parent == NULL)
		return ;
	delete_child(parent->lc);
	delete_child(parent->rc);
	free(parent->token->value);
	free(parent->token);
	free(parent);
}

int	delete_left_child(t_btree_node *parent)
{
	if (parent == NULL)
		return (FALSE);
	if (parent->lc == NULL)
		return (FALSE);
	delete_child(parent->lc);
	parent->lc = NULL;
	return (TRUE);
}

int	delete_right_child(t_btree_node *parent)
{
	if (parent == NULL)
		return (FALSE);
	if (parent->rc == NULL)
		return (FALSE);
	delete_child(parent->lc);
	parent->rc = NULL;
	return (TRUE);
}
