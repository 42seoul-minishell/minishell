/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:19:50 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:19:51 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	exec_word(t_bintree_node *root)
{
	pid_t	pid;
	int		status;
	int		p_status;

	signal(SIGINT, &sig_exec);
	signal(SIGQUIT, &sig_exec);
	p_status = EXIT_SUCCESS;
	if (root->token->type == T_BRACKET)
		return (exec_parens(root));
	else if (root->command && (check_builtin(root->command) == EXIT_SUCCESS))
		return (run_builtin(root));
	else
	{
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		else if (pid == 0)
		{
			status = exec_word_child(root);
			exit(status);
		}
		waitpid(pid, &p_status, 0);
		return (check_status(p_status));
	}
}

int	exec_last_word_child(t_bintree_node *root, t_pipe p)
{
	dup2(p.prev, STDIN_FILENO);
	close(p.prev);
	if (root->token->type == T_BRACKET)
		exec_parens(root);
	else
	{
		if (check_builtin(root->command) == EXIT_SUCCESS)
			p.status = run_builtin(root);
		else
			p.status = exec_word_child(root);
	}
	return (p.status);
}

int	exec_word_child(t_bintree_node *root)
{
	char	*path;
	char	**env;
	char	**cmd_list;

	if (redirection(root) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (root->command)
	{
		cmd_list = exec_token_str_list(root->command);
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
