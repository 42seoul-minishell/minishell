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

static char	*custom_strtrim(char const *str)
{
	int		start;
	int		end;
	char	*res;
	char	*tmp;
	int		i;

	start = 1;
	end = ft_strlen(str) - 1;
	tmp = (char *)ft_malloc((end - start + 1) * sizeof(char));
	i = 0;
	while (start + i < end)
	{
		tmp[i] = str[start + i];
		i++;
	}
	tmp[i] = '\0';
	res = ft_strtrim(tmp, " ");
	free(tmp);
	return (res);
}

static char	**_set_argv(t_list *node)
{
	char	**argv;
	char	*cmd;

	argv = (char **)ft_malloc(sizeof(char *) * 3);
	cmd = custom_strtrim(((t_token *)node->content)->value);
	argv[0] = ft_strdup("./minishell");
	argv[1] = cmd;
	argv[2] = NULL;
	return (argv);
}

void	execute_bracket(t_bintree_node *node)
{
	char	*path;
	char	**argv;

	path = ft_strjoin(g_global.origin_path, "/minishell");
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
	printf("\n");
}
