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

static char	**_token_list_to_array(t_list *token_lst)
{
	char	**cmd_arr;
	size_t	size;
	size_t	idx;
	t_token	*token;
	t_list	*node;

	node = token_lst;
	size = 0;
	idx = 0;
	while (node)
	{
		token = node->content;
		if (token->type != CMD)
			break ;
		size++;
		node = node->next;
	}
	cmd_arr = ft_malloc(sizeof(char *) * (size + 1));
	cmd_arr[size] = NULL;
	node = token_lst;
	while (idx < size)
	{
		token = node->content;
		cmd_arr[idx] = token->value;
		node = node->next;
		idx++;
	}
	return (cmd_arr);
}

static void	_run_cmd(char *abs_path, char *argv[])
{
	if (access(abs_path, X_OK) == -1)
		exit_error("MINISHELL");
	if (execve(abs_path, argv, g_global.envp_arr) == -1)
		exit_error("MINISHELL\n");
}

char	*get_abs_path(char *cmd)
{
	int		i;
	char	*check;
	char	**paths;

	i = 0;
	check = NULL;
	paths = ft_split(search(g_global.envp, "PATH"), ':', 0);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	if (paths)
	{
		cmd = ft_strjoin("/", cmd);
		while (paths[i])
		{
			check = ft_strjoin(paths[i], cmd);
			if (access(check, X_OK) == 0)
				return (check);
			free(check);
			i++;
		}
	}
	return (NULL);
}

static void	_exec_word_child(t_bintree_node *node, int in_fd, int out_fd)
{
	char	*path;
	char	**cmd_arr;

	dup2(in_fd, 0);
	dup2(out_fd, 1);
	if (in_fd != 0)
		close(in_fd);
	if (out_fd != 1)
		close(out_fd);
	if (node->token_lst)
	{
		if (((t_token *)node->token_lst->content)->type == BRACKET)
			execute_bracket(node);
		else
		{
			cmd_arr = _token_list_to_array(node->token_lst);
			path = get_abs_path(cmd_arr[0]);
			if (!path)
			{
				not_found_error(cmd_arr[0]);
				exit(127);
			}
			_run_cmd(path, cmd_arr);
		}
	}
	exit(0);
}

static void	_set_child_info(int pid, int out_fd, int status)
{
	t_children	*child;

	child = ft_malloc(sizeof(t_children));
	child->pid = pid;
	child->status = status;
	if (out_fd != 1)
		close(out_fd);
	ft_lstadd_back(&g_global.pipe_status, ft_lstnew(child));
}

static int	_set_in(t_bintree_node *node, int in_fd)
{
	t_token	*token;
	t_token	*file_token;
	t_list	*lst;

	lst = node->token_lst;
	while (lst && lst->next)
	{
		token = lst->content;
		if (token->type == INP_RDIR || token->type == HERE_DOC)
		{
			file_token = lst->next->content;
			if (in_fd != 0)
				close(in_fd);
			if (token->type == INP_RDIR)
				in_fd = open(file_token->value, O_RDONLY);
			else
				in_fd = node->fd[0];
			if (in_fd == -1)
			{
				perror(file_token->value);
				break ;
			}
			lst = lst->next;
		}
		lst = lst->next;
	}
	return (in_fd);
}

static int	_set_out(t_bintree_node *node, int out_fd)
{
	t_token	*token;
	t_token	*file_token;
	t_list	*lst;

	lst = node->token_lst;
	while (lst && lst->next)
	{
		token = lst->content;
		if (token->type == OUT_RDIR || token->type == APP_RDIR)
		{
			file_token = lst->next->content;
			if (out_fd != 1)
				close(out_fd);
			if (token->type == OUT_RDIR)
				out_fd = open(file_token->value, O_CREAT | O_WRONLY | O_TRUNC | O_CLOEXEC, 0644);
			else
				out_fd = open(file_token->value, O_APPEND | O_CREAT | O_WRONLY | O_CLOEXEC, 0644);
			if (out_fd == -1)
			{
				perror(file_token->value);
				break ;
			}
			lst = lst->next;
		}
		lst = lst->next;
	}
	return (out_fd);
}

void	execute_command(t_bintree_node *node, int in_fd, int out_fd, int is_pipe)
{
	pid_t	pid;
	int		is_builtin;

	if (node->type == TN_HEREDOC || node->type == TN_RDIR)
	{
		in_fd = _set_in(node, in_fd);
		out_fd = _set_out(node, out_fd);
	}
	if (((t_token *)node->token_lst->content)->type != CMD \
		&& ((t_token *)node->token_lst->content)->type != BRACKET)
		return (_set_child_info(0, out_fd, 0));
	is_builtin = check_builtin(node->token_lst);
	if (is_pipe || !is_builtin)
	{
		pid = fork();
		if (pid == -1)
			exit_error("Error: fork()");
		if (pid == 0)
		{
			set_fork_signal();
			if (is_builtin)
				exit(execute_builtin(node->token_lst, out_fd));
			else
				_exec_word_child(node, in_fd, out_fd);
		}
		else
			_set_child_info(pid, out_fd, -1);
	}
	else if (is_builtin)
		_set_child_info(0, out_fd, execute_builtin(node->token_lst, out_fd));
}
