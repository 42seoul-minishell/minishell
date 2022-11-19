/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:35:57 by bolee             #+#    #+#             */
/*   Updated: 2022/11/19 00:38:03 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	get_expans_list(t_token *token, t_token **expan_token)
{
	struct dirent	*dirent;
	DIR				*dir;
	t_aster			*ast;

	ast = malloc(sizeof(t_aster));
	ast->prefix = get_prefix(token->content);
	ast->suffix = get_suffix(token->content);
	dir = opendir(".");
	while (1)
	{
		dirent = readdir(dir);
		if (!dirent)
			break ;
		if (!ast->prefix && !ast->suffix)
			case_zero(dirent->d_name, token, expan_token);
		else if (ast->prefix && !ast->suffix)
			case_one(dirent->d_name, ast->prefix, token, expan_token);
		else if (!ast->prefix && ast->suffix)
			case_two(dirent->d_name, ast->suffix, token, expan_token);
		else if (ast->prefix && ast->suffix)
			case_three(dirent->d_name, ast, token, expan_token);
	}
	closedir(dir);
}

static int	is_wlidcard(t_token token)
{
	int		result;

	result = 0;
	if (ft_strchr(token.content, '*'))
	{
		result = 1;
	}
	return (result);
}

void	wildcard(t_doubly_list *lst)
{
	t_doubly_node	*node;

	while (tmp)
	{
		if (is_wildcard(*tmp))
		{
			get_expans_list(tmp, &expan_tokens);
			token_replace(tokens_list, tmp, expan_tokens);
		}
		tmp = tmp->next;
	}
}
