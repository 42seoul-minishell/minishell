/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:19:26 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:19:27 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_and(t_bintree_node *node)
{
	if (!node->lc)
		syntax_error("&&", 0);
	executor(node->lc, 0, 1, 0);
	wait_child();
	if (get_pipe_status() == 0)
	{
		ft_lstclear(&g_global.pipe_status, free);
		g_global.pipe_status = NULL;
		executor(node->rc, 0, 1, 0);
		wait_child();
	}
}

void	execute_or(t_bintree_node *node)
{
	if (!node->lc)
		syntax_error("||", 0);
	executor(node->lc, 0, 1, 0);
	wait_child();
	if (get_pipe_status() != 0)
	{
		ft_lstclear(&g_global.pipe_status, free);
		g_global.pipe_status = NULL;
		executor(node->rc, 0, 1, 0);
		wait_child();
	}
}
