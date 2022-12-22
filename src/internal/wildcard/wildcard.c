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

static int	_check_matched(char *wildcard, char dirent[])
{
	if (*dirent == '\0')
	{
		while (*wildcard)
		{
			if (*wildcard != '*' && *wildcard != '\0')
				return (0);
			wildcard++;
		}
		return (1);
	}
	if ((*wildcard == *dirent) && _check_matched(wildcard + 1, dirent + 1))
		return (1);
	if (*wildcard == '*')
		return (_check_matched(wildcard + 1, dirent) \
			|| _check_matched(wildcard, dirent + 1));
	return (0);
}

static char	**_ft_dp_join(char **dst, char **src)
{
	char	**ret;
	size_t	total_len;
	size_t	idx;
	size_t	jdx;

	idx = 0;
	total_len = 0;
	while (dst && dst[idx++])
		total_len++;
	idx = 0;
	while (src && src[idx++])
		total_len++;
	ret = (char **)dp_malloc(sizeof(char *) * (total_len + 1));
	ret[total_len] = NULL;
	idx = 0;
	jdx = 0;
	while (dst && dst[jdx])
		ret[idx++] = dst[jdx++];
	jdx = 0;
	while (src && src[jdx])
		ret[idx++] = src[jdx++];
	if (dst)
		free(dst);
	if (src)
		free(src);
	return (ret);
}

static char	**_get_matched_name(char **path_token, char *path, int curr_depth, DIR *dir)
{
	struct dirent	*_dirent;
	char			*matched_dir;
	char			**ret;

	ret = NULL;
	if (!path_token[curr_depth])
	{
		ret = (char **)dp_malloc(sizeof(char *) * 2);
		ret[0] = ft_strdup(path);
		ret[1] = NULL;
		if (dir)
			closedir(dir);
		return (ret);
	}
	if (!dir)
		return (NULL);
	if (*path_token[curr_depth] == '/')
	{
		matched_dir = ft_strjoin(path, "/");
		ret = _get_matched_name(path_token, \
			matched_dir, curr_depth + 1, opendir(matched_dir));
		free(matched_dir);
	}
	else
	{
		_dirent = readdir(dir);
		while (_dirent)
		{
			if (!(ft_strchr(path_token[curr_depth], '*') && _dirent->d_name[0] == '.') \
				&& (path_token[curr_depth + 1] == NULL \
				|| (*path_token[curr_depth + 1] == '/' && _dirent->d_type == 4)) \
				&& _check_matched(path_token[curr_depth], _dirent->d_name))
			{
				matched_dir = ft_strjoin(path, _dirent->d_name);
				ret = _ft_dp_join(ret, _get_matched_name(path_token, matched_dir, curr_depth + 1, opendir(matched_dir)));
				free(matched_dir);
			}
			_dirent = readdir(dir);
		}
	}
	if (dir)
		closedir(dir);
	return (ret);
}

void	wildcard(t_doubly_list *lst)
{
	char			**res;
	t_doubly_node	*node;
	char			*path;
	DIR				*dir;
	char			**path_token;

	node = lst->header.next;
	while (node)
	{
		if (ft_strchr(node->token->value, '*'))
		{
			path_token = ft_split(node->token->value, '/', 1);
			if (*path_token[0] == '/')
				dir = opendir("/");
			else
				dir = opendir(".");
			path = ft_strdup("");
			res = _get_matched_name(path_token, path, 0, dir);
			free(path);
			if (res)
			{
				free(node->token->value);
				node->token->value = wildcard_join(res);
				free(res);
			}
			printf("wildcard parse result: %s\n", node->token->value);
			free_dp((void **)path_token);
		}
		node = node->next;
		if (node == lst->header.next)
			break ;
	}
}
