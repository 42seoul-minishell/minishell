/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:19:43 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:19:44 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_fd_all_clear(t_bintree_node *node, t_bintree_node *target)
{
	if (node->lc != target && node->rc != target)
	{
		if (node->lc)
			_fd_all_clear(node->lc, target);
		if (node->rc)
			_fd_all_clear(node->rc, target);
	}
	if (node->fd[0] != 0)
		close(node->fd[0]);
	if (node->fd[1] != 1)
		close(node->fd[1]);
}

static void	_exec_word_child(t_bintree_node *node, int in_fd, int out_fd)
{
	char	*path;
	char	**cmd_arr;

	dup2(in_fd, 0);
	dup2(out_fd, 1);
	_fd_all_clear(g_global.tree->root, node);
	if (node->token_lst)
	{
		if (((t_token *)node->token_lst->content)->type == BRACKET)
			execute_bracket(node);
		else
		{
			cmd_arr = token_list_to_array(node->token_lst);
			path = get_abs_path(cmd_arr[0]);
			if (!path)
				not_found_error(cmd_arr[0]);
			run_cmd(path, cmd_arr);
		}
	}
	exit(0);
}

static void	_set_child_info(int pid, int in_fd, int out_fd, int status)
{
	t_children	*child;

	child = ft_malloc(sizeof(t_children));
	child->pid = pid;
	child->status = status;
	if (in_fd != STDIN_FILENO)
		close(in_fd);
	if (out_fd != STDOUT_FILENO)
		close(out_fd);
	ft_lstadd_back(&g_global.pipe_status, ft_lstnew(child));
}

static void	_fork_exec_cmd(t_bintree_node *node, int in_fd, \
								int out_fd, int is_builtin)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		exit_error("Error: fork()");
	if (pid == 0)
	{
		set_fork_signal();
		if (is_builtin)
			exit(execute_builtin(node->token_lst, out_fd, 1));
		else
			_exec_word_child(node, in_fd, out_fd);
	}
	else
		_set_child_info(pid, in_fd, out_fd, -1);
}

void	execute_command(t_bintree_node *node, int in_fd, \
							int out_fd, int is_pipe)
{
	int		is_builtin;

	if (node->type == TN_HEREDOC || node->type == TN_RDIR)
	{
		in_fd = set_in(node, in_fd);
		out_fd = set_out(node, out_fd);
	}
	if (((t_token *)node->token_lst->content)->type != CMD \
		&& ((t_token *)node->token_lst->content)->type != BRACKET)
		return (_set_child_info(0, in_fd, out_fd, 0));
	is_builtin = check_builtin(node->token_lst);
	if (is_pipe || !is_builtin)
		_fork_exec_cmd(node, in_fd, out_fd, is_builtin);
	else if (is_builtin)
		_set_child_info(0, in_fd, out_fd, \
			execute_builtin(node->token_lst, out_fd, 0));
}
