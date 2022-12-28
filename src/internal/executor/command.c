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

// int	exec_last_word_child(t_tree_node *node, t_pipe p)
// {
// 	dup2(p.prev, STDIN_FILENO);
// 	close(p.prev);
// 	if (node->type == TN_PARENS)
// 		exec_parens(node);
// 	else
// 	{
// 		if (check_builtin(node->command) == EXIT_SUCCESS)
// 			p.status = run_builtin(node);
// 		else
// 			p.status = exec_word_child(node);
// 	}
// 	return (p.status);
// }
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

	fprintf(g_global.fp, "node: %s\n",((t_token *) node->token_lst->content)->value);
	fprintf(g_global.fp, "fd[0]: %i, fd[1]: %i\n", fd[0], fd[1]);
	fprintf(g_global.fp, "sup_fd[0]: %i, sup_fd[1]: %i\n", sup_fd[0], sup_fd[1]);
	fprintf(g_global.fp, "Hello History\n");
	if (dir == 0 && fd[1] != 1)
		dup2(fd[1], 1);
	if (dir == 1)
	{
		if (sup_fd[1] != 1)
			dup2(sup_fd[1], 1);
		if (fd[0] != 0)
		{
			dup2(fd[0], 0);
			close(fd[0]);
		}
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
	if (fd[0] != 0)
		close(fd[0]);
	printf("pid, status%i%i", pid, *status);
	waitpid(pid, status, 0);
}

int	execute_command(t_bintree_node *node, int fd[], int sup_fd[], int dir)
{
	pid_t	pid;
	int		status;
	int		p_status;

	fprintf(g_global.fp, "node: %s\n",((t_token *) node->token_lst->content)->value);
	fprintf(g_global.fp, "fd[0]: %i, fd[1]: %i\n", fd[0], fd[1]);
	fprintf(g_global.fp, "sup_fd[0]: %i, sup_fd[1]: %i\n", sup_fd[0], sup_fd[1]);
	fprintf(g_global.fp, "Hello tistory\n");

	// set_execute_signal();
	p_status = 0;

	pid = fork();
	if (pid == -1)
		exit(1);
	else if (pid == 0)
	{
		status = _exec_word_child(node, fd, sup_fd, dir);
		// exit(status);
	}
	else
		_wait_word_child(pid, fd, &p_status);
	return (check_status(p_status));
}

// if (node->lc)
// 	executor(node->lc);
// if (node->rc)
// 	executor(node->rc);
