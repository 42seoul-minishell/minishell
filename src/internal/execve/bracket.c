/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bracket.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:04:59 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/16 19:13:37 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	execute_bracket(t_bintree_node *root)
{
	pid_t	pid;
	int		status;
	char	*cmd_line;

	status = EXIT_SUCCESS;
	cmd_line = exec_rm_char(root->token);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (pid == 0)
	{
		if (cmd_line)
			executor(cmd_line);
		exit(EXIT_SUCCESS);
	}
	waitpid(pid, &status, 0);
	return (check_status(status));
}
