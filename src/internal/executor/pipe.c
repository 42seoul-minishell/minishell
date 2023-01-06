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

#include "minishell.h"

void	execute_pipe(t_bintree_node	*node, int in_fd, int out_fd)
{
	if (pipe(node->fd) == -1)
		exit_error("Error: pipe()");
	if (node->lc)
		executor(node->lc, in_fd, node->fd[1], 1);
	if (node->rc)
		executor(node->rc, node->fd[0], out_fd, 1);
}

static void	_fork_heredoc(int fd[], char *limiter)
{
	char	*line;

	line = readline("> ");
	while (line && ft_strcmp(limiter, line) != 0)
	{
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
		line = readline("> ");
	}
	if (line)
		free(line);
	close(fd[1]);
	exit(0);
}

static void	_here_doc(t_bintree_node *node)
{
	t_list	*lst;
	char	*line;
	char	*limiter;
	int		pid;
	int		status;

	lst = node->token_lst;
	line = NULL;
	status = 0;
	while (lst && lst->next)
	{
		if (((t_token *)lst->content)->type == HERE_DOC)
		{
			limiter = ((t_token *)lst->next->content)->value;
			pid = fork();
			if (pid == -1)
				exit_error("Error: fork()");
			if (pid == 0)
			{
				set_fork_signal();
				_fork_heredoc(node->fd, limiter);
			}
			else
			{
				// char	test[10000];
				close(node->fd[1]);
				pid = wait(&status);
				// read(node->fd[0], test, 10000);
				// printf("read heredoc %s\n", test);
				if (check_status(status) != 0)
					break ;
			}
			lst = lst->next;
		}
		lst = lst->next;
	}

}

void	set_heredoc(t_bintree_node *node)
{
	if (pipe(node->fd) == -1)
		exit_error("Error: pipe()");
	if (node->type == TN_HEREDOC)
		_here_doc(node);
	if (node->lc)
		set_heredoc(node->lc);
	if (node->lc)
		set_heredoc(node->rc);
}
