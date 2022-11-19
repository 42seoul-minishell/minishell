#include "../../../include/minishell.h"

void	builtin_unset(char *key)
{
	delete_item_by_key(g_global->envp, key);
}
