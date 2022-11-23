/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:05:11 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/16 19:05:11 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	execute_command(t_bintree_node *node)
{
	char	**split;

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
		exit_on_error(CMDNFERR);
	free(split);
}
