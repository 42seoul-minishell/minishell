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
	executor(node->lc, 0, 1);
	if (!g_global.status)
		executor(node->rc, 0, 1);
}

void	execute_or(t_bintree_node *node)
{
	if (!node->lc)
		syntax_error("||", 0);
	executor(node->lc, 0, 1);
	if (g_global.status)
		executor(node->rc, 0, 1);
}
