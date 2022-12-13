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

#include "../../../include/minishell.h"

static void _separate_cmd(t_bintree_node *node)
{
	char **split;

	if (!node)
		return;
	split = ft_split(node->token->value, ' ');
	if (!split)
		exit(1);
	if (ft_strncmp(split[0], "echo", ft_strlen(split[0])) == 0)
		builtin_echo("echo", 0, 0);
	else if (ft_strncmp(split[0], "cd", ft_strlen(split[0])) == 0)
		builtin_cd(split[1]);
	else if (ft_strncmp(split[0], "pwd", ft_strlen(split[0])) == 0)
		builtin_pwd();
	else if (ft_strncmp(split[0], "export", ft_strlen(split[0])) == 0)
		builtin_export();
	else if (ft_strncmp(split[0], "unset", ft_strlen(split[0])) == 0)
		builtin_unset();
	else if (ft_strncmp(split[0], "env", ft_strlen(split[0])) == 0)
		builtin_env();
	else if (ft_strncmp(split[0], "exit", ft_strlen(split[0])) == 0)
		builtin_exit();
	else
		not_found_error(split[0]);
	free(split);
}

void execute_command(t_bintree_node *node)
{
	executor(node->lc);
	_separate_cmd(node);
	executor(node->rc);
}
