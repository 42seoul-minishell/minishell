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
void	init_fd(int fd[])
{
	fd[0] = 0;
	fd[1] = 1;
}

void	executor(t_bintree_node	*root, int sup_fd[], int dir)
{
	int	fd[2];

	init_fd(fd);
	if (!root)
		return (1);
	if (root->type == TN_RDIR)
		g_golbal.status = execute_redirect(root, fd);

	else if (root->type == TN_BRACKET)
		g_golbal.status = execute_bracket(root, sup_fd, dir);
	else if (root->type == TN_AND)
		execute_and(root, fd, dir);
	else if (root->type == TN_OR)
		execute_or(root, fd, dir);
	else if (root->type == TN_PIPE)
		g_golbal.status = execute_pipe(root, fd);
	// return (g_golbal.status);
}

int	serve_status(char *cmd)
{
	int	status;

	printf("cmd = %s\n", cmd);
	status = EXIT_SUCCESS;
	return (status);
}
