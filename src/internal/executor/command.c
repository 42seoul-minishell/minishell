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
	char 	**cmd_arr;
	size_t	size;
	size_t	idx;
	t_token	*token;
	t_list	*node;

	node = token_lst;
	size = 0;
	idx = 0;
	while (node)
	{
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

static int	_exec_word_child(t_bintree_node *node, int fd[], int sup_fd[], int dir)
{
	char	*path;
	char	**cmd_arr;

	if (dir == 0)
	{
		dup2(fd[0], 0);
		dup2(fd[1], 1);
	}
	if (dir == 1)
	{
		dup2(fd[0], 0);
		dup2(sup_fd[1], 1);
		if (fd[0] != 0)
			close(fd[0]);
		if (fd[1] != 1)
			close(fd[1]);
	}
	if (node->token_lst)
	{
		cmd_arr = _token_list_to_array(node->token_lst);
		path = get_abs_path(cmd_arr[0]);
		_run_cmd(path, cmd_arr);
	}
	return (EXIT_SUCCESS);
}

static void	_wait_word_child(int pid, int fd[], int *status)
{
	if (fd[1] != 1)
		close(fd[1]);
	waitpid(pid, status, 0);
}

int	execute_command(t_bintree_node *node, int fd[], int sup_fd[], int dir)
{
	pid_t	pid;
	int		p_status;

	set_execute_signal();
	p_status = 0;
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		_exec_word_child(node, fd, sup_fd, dir);
	else
		_wait_word_child(pid, fd, &p_status);
	return (check_status(p_status));
}
