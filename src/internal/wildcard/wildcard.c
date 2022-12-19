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
	tmp = join_with_blank(res, str);
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
	dir = get_dir_pointer(wildcard);
	if (wildcard->prefix && ft_strchr(wildcard->prefix, '/') && !dir)
		return (NULL);
	else if (!dir)
		exit_error("\033[31mError: opendir(): Failed to open directory\n\033[0m");
	res = _convert_wildcard(dir, wildcard);
	closedir(dir);
	free(wildcard->prefix);
	free(wildcard->suffix);
	free(wildcard);
	return (res);
}

static char	*_convert_str(char *str)
{
	char	**split;
	char	*res;
	char	*tmp;
	int		i;

	split = ft_split(str, ' ');
	if (!split)
		exit_error("\033[31mError: ft_split(): Failed to split string\n\033[0m");
	i = 0;
	while (split[i])
	{
		if (ft_strchr(split[i], '*'))
		{
			tmp = _wildcard_to_str(split[i]);
			if (tmp)
			{
				free(split[i]);
				split[i] = tmp;
			}
		}
		i++;
	}
	res = wildcard_join(split);
	free_dp((void **) split);
	return (res);
}

void	wildcard(t_doubly_list *lst)
{
	char			*res;
	t_doubly_node	*node;

	node = lst->header.next;
	while (node)
	{
		if (ft_strchr(node->token->value, '*'))
		{
			res = _convert_str(node->token->value);
			if (res)
			{
				free(node->token->value);
				node->token->value = res;
			}
		}
		node = node->next;
		if (node == lst->header.next)
			break ;
	}
}
