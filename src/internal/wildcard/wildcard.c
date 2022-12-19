/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:28:08 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:28:09 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*_set_res(char *res, char *str)
{
	char	*tmp;

	if (!res)
		return (str);
	tmp = ft_strjoin(res, str);
	if (!tmp)
		exit_error("\033[31mError: ft_strjoin(): Failed to join strings\n\033[0m");
	free(res);
	free(str);
	return (tmp);
}

static char	*_convert_wildcard(DIR *dir, t_wildcard *wildcard)
{
	char			*res;
	char			*tmp;
	struct dirent	*dirent;

	res = NULL;
	dirent = readdir(dir);
	while (dirent)
	{
		if (!wildcard->prefix && !wildcard->suffix)
			tmp = nothing_have(dirent->d_name);
		else if (wildcard->prefix && !wildcard->suffix)
			tmp = only_prefix(dirent->d_name, wildcard->prefix);
		else if (!wildcard->prefix && wildcard->suffix)
			tmp = only_suffix(dirent->d_name, wildcard->suffix);
		else
			tmp = both_have(dirent->d_name, wildcard);
		if (!tmp)
		{
			dirent = readdir(dir);
			continue ;
		}
		res = _set_res(res, tmp);
		dirent = readdir(dir);
	}
	return (res);
}

static char	*_wildcard_to_str(char *str)
{
	char		*res;
	DIR			*dir;
	t_wildcard	*wildcard;

	wildcard = (t_wildcard *)sp_malloc(sizeof(t_wildcard));
	wildcard->prefix = get_prefix(str);
	wildcard->suffix = get_suffix(str);
	if (wildcard->prefix && wildcard->prefix[ft_strlen(wildcard->prefix) - 1] == '/')
		dir = opendir(wildcard->prefix);
	else
		dir = opendir(".");
	// 에러 메세지 수정 필요
	if (!dir)
		exit_error("\033[31mError: opendir(): Failed to open directory\n\033[0m");
	// dir에 따라 분기를 나누어 처리할 필요가 있음
	// 안 그러면 prefix가 없는 파일이름을 가지고 와일드 카드를 대체하는 작업을 진행함
	res = _convert_wildcard(dir, wildcard);
	closedir(dir);
	free(wildcard->prefix);
	free(wildcard->suffix);
	free(wildcard);
	return (res);
}

void	wildcard(t_doubly_list *lst)
{
	char			*tmp;
	t_doubly_node	*node;

	node = lst->header.next;
	while (node)
	{
		if (ft_strchr(node->token->value, '*'))
		{
			// wildcard 이전에 문자를 없애지 않도록 수정해야함
			// 결과 값에 공백 추가해야함
			tmp = _wildcard_to_str(node->token->value);
			if (tmp && ft_strlen(tmp))
			{
				free(node->token->value);
				node->token->value = tmp;
			}
			else if (tmp)
				free(tmp);
		}
		node = node->next;
		if (node == lst->header.next)
			break ;
	}
}
