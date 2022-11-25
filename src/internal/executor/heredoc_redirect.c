/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:04:17 by bolee             #+#    #+#             */
/*   Updated: 2022/11/23 17:04:18 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void interrupt_here_document(int signal)
{
	if (signal == SIGINT)
	{
		g_global->status = 130;
		ft_putchar_fd('\n', 1);
		exit(130);
	}
}

static int _create_tmp_file(void)
{
	int fd;

	fd = open(TMP_FILE, O_RDONLY | O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		ft_putstr_fd(strerror(errno), 2);
	return (fd);
}

static void _get_input(int tmp_fd, char *eof)
{
	char *input;

	signal(SIGINT, interrupt_here_document);
	while (TRUE)
	{
		input = readline("> ");
		if (!input)
		{
			ft_putstr_fd("warning: here-document delimited by end-of-file", 2);
			close(tmp_fd);
			exit(0);
		}
		if (ft_strcmp(input, eof))
			ft_putendl_fd(input, tmp_fd);
		else
		{
			close(tmp_fd);
			free(input);
			break;
		}
		free(input);
	}
	exit(0);
}

static void _make_tmp_file_input(void)
{
	int tmp_fd;

	tmp_fd = open(TMP_FILE, O_RDONLY);
	unlink(TMP_FILE);
	dup2(tmp_fd, 1);
	close(tmp_fd);
}

void heredoc_redirect(t_bintree_node *node, char *eof, int *save_fd)
{
	int tmp_fd;
	int save_fd_out;
	int pid;
	int status;

	tmp_fd = _create_tmp_file();
	if (tmp_fd == -1)
		return;
	save_fd_out = dup(0);
	dup2(save_fd[0], STDOUT_FILENO);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
		_get_input(tmp_fd, eof);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		close(tmp_fd);
		g_global->status = WEXITSTATUS(status);
	}
	_make_tmp_file_input();
	dup2(save_fd_out, STDOUT_FILENO);
	close(save_fd_out);
}
