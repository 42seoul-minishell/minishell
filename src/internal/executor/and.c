#include "../../../include/minishell.h"

void execute_and(t_bintree_node *node)
{
	executor(node->lc);
	if (g_global->status == 0)
		executor(node->rc);
}
