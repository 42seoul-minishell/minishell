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

#include "../../../include/minishell.h"

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
		res = _set_res(res, tmp);
		dirent = readdir(dir);
	}
	return (tmp);
}

static char	*_wildcard_to_str(char *str)
{
	char		*res;
	DIR			*dir;
	t_wildcard *wildcard;

	wildcard = (t_wildcard *)sp_malloc(sizeof(t_wildcard));
	wildcard->prefix = get_prefix(str);
	wildcard->suffix = get_suffix(str);
	if (wildcard->prefix[ft_strlen(wildcard->prefix) - 1] == '/')
		dir = opendir(wildcard->prefix);
	else
		dir = opendir(".");
	if (!dir)
	{
		printf("%s\n", strerror(errno));
		return (NULL);
	}
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
			tmp = _wildcard_to_str(node->token->value);
			free(node->token->value);
			node->token->value = tmp;
		}
		node = node->next;
		if (node == lst->header.next)
			break ;
	}
}
