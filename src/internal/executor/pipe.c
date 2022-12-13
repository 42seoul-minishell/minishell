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

static void _lc_process(t_bintree_node *node, int *fd)
{
	close(fd[0]);
	dup2(fd[1], g_global.fd_stdout);
	g_global.fd_stdout = fd[1];
	close(fd[1]);
	executor(node->lc);
}

static void _rc_process(t_bintree_node *node, int *fd)
{
	close(fd[1]);
	dup2(fd[0], g_global.fd_stdin);
	g_global.fd_stdin = fd[0];
	close(fd[0]);
	executor(node->rc);
}

int execute_pipe(t_bintree_node *node)
{
	int		fd[2];
	int		status;
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid < 0)
		exit_error(strerror(errno));
	if (pid == 0)
	{
		_rc_process(node, fd);
		waitpid(pid, &status, 0);
		// 상태 저장
		g_global.status = check_status(status);
	}
	else
		_lc_process(node, fd);
	return (g_global.status);
}
