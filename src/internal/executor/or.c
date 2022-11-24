#include "../../../include/minishell.h"

void execute_or(t_bintree_node *node)
{
	executor(node->lc);
	executor(node->rc);
}
