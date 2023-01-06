/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsoh <junsoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:40:26 by junsoh            #+#    #+#             */
/*   Updated: 2023/01/06 19:40:26 by junsoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execution_main(void)
{
	g_global.status = 0;
	set_heredoc_signal();
	set_heredoc(g_global.tree->root);
	if (g_global.status == 0)
	{
		set_execute_signal();
		display_ctrlx_set(DISPLAY);
		executor(g_global.tree->root, 0, 1, 0);
		wait_child();
		reset_global();
		display_ctrlx_set(NODISPLAY);
	}
	else
	{
		clear_bintree(g_global.tree->root);
		g_global.tree->root = NULL;
	}
}

void	execution_sub(void)
{
	set_heredoc_signal();
	set_heredoc(g_global.tree->root);
	if (g_global.status == 0)
	{
		set_execute_signal();
		display_ctrlx_set(DISPLAY);
		executor(g_global.tree->root, 0, 1, 0);
		wait_child();
		reset_global();
		delete_table(g_global.envp);
		display_ctrlx_set(NODISPLAY);
	}
	else
	{
		clear_bintree(g_global.tree->root);
		g_global.tree->root = NULL;
	}
}
