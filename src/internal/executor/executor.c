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
		return ;
	// if (root->type == TN_RDIR)
	// 	execute_redirect(root, fd);
	if (root->type == TN_WORD)
		execute_command(root, fd, sup_fd, dir);
	// else if (root->type == TN_BRACKET)
	// 	g_global.status = execute_bracket(root, sup_fd, dir);
	else if (root->type == TN_AND)
		execute_and(root, fd);
	else if (root->type == TN_OR)
		execute_or(root, fd);
	else if (root->type == TN_PIPE)
	{
		execute_pipe(root, fd);
		execute_command(root->lc, fd, sup_fd, 0);
		execute_command(root->rc, fd, sup_fd, 1);
	}
	// return (g_golbal.status);
}

int	serve_status(char *cmd)
{
	int	status;

	printf("cmd = %s\n", cmd);
	status = EXIT_SUCCESS;
	return (status);
}
