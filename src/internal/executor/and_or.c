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

void	execute_and(t_bintree_node *node, int sup_fd[])
{
	if (!node->lc)
		syntax_error("&&");
	executor(node->lc, sup_fd, 0);
	if (!g_global.status)
		executor(node->rc, sup_fd, 1);
}

void	execute_or(t_bintree_node *node, int sup_fd[])
{
	if (!node->lc)
		syntax_error("||");
	executor(node->lc, sup_fd, 0);
	if (g_global.status)
		executor(node->rc, sup_fd, 1);
}
