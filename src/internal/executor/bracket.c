/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bracket.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:19:33 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:19:34 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	execute_bracket(t_bintree_node *root, int in_fd, int out_fd)
// {
// 	pid_t	pid;
// 	int		status;
// 	char	*cmd_line;

// 	status = EXIT_SUCCESS;
// 	cmd_line = exec_rm_char(root->token);
// 	pid = fork();
// 	if (pid == -1)
// 		exit(0);
// 	if (pid == 0)
// 	{
// 		if (cmd_line)
// 			executor(cmd_line);
// 		exit(EXIT_SUCCESS);
// 	}
// 	waitpid(pid, &status, 0);
// 	return (check_status(status));
// }
