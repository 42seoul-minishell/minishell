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

	while (token_lst)
	{

	}
}

int	exec_word_child(t_bintree_node *node)
{
	char	*path;
	char	**env;
	char	**cmd_list;

	if (redirection(node) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (node->command)
	{
		token_list_to_array
		cmd_list = exec_token_str_list(node->command);
		env = exec_env_str_list();
		if (ft_strchr(cmd_list[0], '/'))
			path = cmd_list[0];
		else
			path = exec_find_path(ft_strjoin("/", cmd_list[0]), env);
		if (execve(path, cmd_list, env) == -1)
		{
			ft_perror(*cmd_list, ": command not found");
			return (127);
		}
	}
	return (EXIT_SUCCESS);
}

static void	_wait_word_child(t_bintree_node *node, int fd[])
{
	int	status;

	close(fd[1]);
	waitpid(NULL, &status, WNOHANG);
}

void	execute_command(t_bintree_node *node, int fd[], int sup_fd[], int dir)
{
	pid_t	pid;
	int		status;
	int		p_status;

	set_execute_signal();
	p_status = 0;
	if (check_builtin(node->lst) == TRUE)
		return (execute_builtin(node->lst));
	else
	{
		pid = fork();
		if (pid == -1)
			exit(1);
		else if (pid == 0)
		{
			status = exec_word_child(node);
			exit(status);
		}
		else
			wait_word_child(node);
		waitpid(pid, &p_status, 0);
		return (check_status(p_status));
	}
}

// if (node->lc)
// 	executor(node->lc);
// if (node->rc)
// 	executor(node->rc);
