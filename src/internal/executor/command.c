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
	{
		perror(": permission denied");
		exit(127);
	}
	if (execve(abs_path, argv, g_global.envp_arr) == -1)
	{
		perror(": command not found");
		exit(127);
	}
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

static int	_exec_word_child(t_bintree_node *node, int in_fd, int out_fd)
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
		cmd_arr = _token_list_to_array(node->token_lst);
		path = get_abs_path(cmd_arr[0]);
		_run_cmd(path, cmd_arr);
	}
	return (EXIT_SUCCESS);
}

static void	_wait_word_child(int pid, int out_fd, int *status)
{
	if (out_fd != 1)
		close(out_fd);
	waitpid(pid, status, WNOHANG);
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
		if (token->type == INP_RDIR)
		{
			if (in_fd != 0)
				close(in_fd);
			file_token = lst->next->content;
			in_fd = open(file_token->value, O_RDONLY);
			lst = lst->next;
		}
		else if (token->type == HERE_DOC)
		{
			if (in_fd != 0)
				close(in_fd);
			in_fd = node->fd[0];
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
		if (token->type == OUT_RDIR)
		{
			file_token = lst->next->content;
			if (out_fd != 1)
				close(out_fd);
			out_fd = open(file_token->value, O_CREAT | O_WRONLY | O_TRUNC | O_CLOEXEC, 0644);
			lst = lst->next;
		}
		else if (token->type == APP_RDIR)
		{
			file_token = lst->next->content;
			if (out_fd != 1)
				close(out_fd);
			out_fd = open(file_token->value, O_APPEND | O_CREAT | O_WRONLY | O_TRUNC | O_CLOEXEC, 0644);
			lst = lst->next;
		}
		lst = lst->next;
	}
	return (out_fd);
}

int	execute_command(t_bintree_node *node, int in_fd, int out_fd)
{
	pid_t	pid;
	int		p_status;

	set_execute_signal();
	if (node->type == TN_HEREDOC || node->type == TN_RDIR)
	{
		in_fd = _set_in(node, in_fd);
		out_fd = _set_out(node, out_fd);
	}
	if (check_builtin(node->token_lst))
	{
		p_status = execute_builtin(node->token_lst, out_fd);
		if (out_fd != 1)
			close(out_fd);
		return (p_status);
	}
	p_status = 0;
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		_exec_word_child(node, in_fd, out_fd);
	else
		_wait_word_child(pid, out_fd, &p_status);
	return (check_status(p_status));
}
