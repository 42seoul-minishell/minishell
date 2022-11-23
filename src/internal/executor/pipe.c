/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:05:13 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/16 19:05:14 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	lc_process(t_bintree_node *node, int *fd, int *pid)
{
	*pid = fork();
	if (*pid < 0)
		exit(1);
	if (*pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		executor(node->lc);
	}
}

static void	rc_process(t_bintree_node *node, int *fd, int *pid)
{
	*pid = fork();
	if (*pid < 0)
		exit(1);
	if (*pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		executor(node->rc);
	}
}

void	execute_pipe(t_bintree_node *node)
{
	int	fd[2];
	int	pid[2];

	if (pipe(fd) == -1)
		exit(1);
	lc_process(node, fd, &pid[0]);
	if (pid[0])
		rc_process(node, fd, &pid[1]);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
}
