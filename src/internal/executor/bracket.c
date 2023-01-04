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

static char	**_set_argv(t_list *node)
{
	char	**argv;
	char	*cmd;

	argv = (char **)ft_malloc(sizeof(char *) * 3);
	cmd = ft_strtrim(((t_token *)node->content)->value, "()");
	argv[0] = ft_strdup("./minishell");
	argv[1] = cmd;
	argv[2] = NULL;
	return (argv);
}

void	execute_bracket(t_bintree_node *node)
{
	char	*path;
	char	**argv;

	path = ft_strdup("/home/octo/minishell/minishell");
	argv = _set_argv(node->token_lst);
	if (access(path, X_OK) == -1)
	{
		perror(": permission denied");
		exit(127);
	}
	if (execve(path, argv, g_global.envp_arr) == -1)
	{
		perror(": command not found");
		exit(127);
	}
}
