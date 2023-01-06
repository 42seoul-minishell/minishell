/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsoh <junsoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:41:55 by junsoh            #+#    #+#             */
/*   Updated: 2023/01/06 19:41:56 by junsoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	get_token_size(t_list *token_lst)
{
	t_list	*node;
	t_token	*token;
	size_t	size;

	size = 0;
	node = token_lst;
	while (node)
	{
		token = node->content;
		if (token->type != CMD)
			break ;
		size++;
		node = node->next;
	}
	return (size);
}

char	**token_list_to_array(t_list *token_lst)
{
	char	**cmd_arr;
	size_t	size;
	size_t	idx;
	t_token	*token;
	t_list	*node;

	node = token_lst;
	size = get_token_size(token_lst);
	idx = 0;
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

char	*get_abs_path(char *cmd)
{
	int		i;
	char	*check;
	char	**paths;

	i = 0;
	check = NULL;
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
