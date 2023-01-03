/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:19:58 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:19:59 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* execute by preorder */
void	executor(t_bintree_node	*root, int in_fd, int out_fd)
{
	if (!root)
		return ;
	if (root->type >= TN_HEREDOC && root->type <= TN_WORD)
		execute_command(root, in_fd, out_fd);
	// else if (root->type == TN_BRACKET)
	// 	g_global.status = execute_bracket(root, in_fd, out_fd);
	else if (root->type == TN_AND)
		execute_and(root);
	else if (root->type == TN_OR)
		execute_or(root);
	else if (root->type == TN_PIPE)
		execute_pipe(root, in_fd, out_fd);
	// return (g_golbal.status);
}

int	serve_status(char *cmd)
{
	int	status;

	printf("cmd = %s\n", cmd);
	status = EXIT_SUCCESS;
	return (status);
}
