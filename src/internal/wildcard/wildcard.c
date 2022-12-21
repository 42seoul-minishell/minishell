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

// static char	*_set_res(char *res, char *str)
// {
// 	char	*tmp;

// 	if (!res)
// 		return (str);
// 	tmp = join_with_blank(res, str);
// 	if (!tmp)
// 		exit_error("\033[31mError: ft_strjoin(): Failed to join strings\n\033[0m");
// 	free(res);
// 	free(str);
// 	return (tmp);
// }

// static char	*_convert_wildcard(DIR *dir, t_wildcard *wildcard)
// {
// 	char			*res;
// 	char			*tmp;
// 	struct dirent	*dirent;

// 	res = NULL;
// 	dirent = readdir(dir);
// 	while (dirent)
// 	{
// 		if (!wildcard->prefix && !wildcard->suffix)
// 			tmp = nothing_have(dirent->d_name);
// 		else if (wildcard->prefix && !wildcard->suffix)
// 			tmp = only_prefix(dirent->d_name, wildcard->prefix);
// 		else if (!wildcard->prefix && wildcard->suffix)
// 			tmp = only_suffix(dirent->d_name, wildcard->suffix);
// 		else
// 			tmp = both_have(dirent->d_name, wildcard);
// 		if (!tmp)
// 		{
// 			dirent = readdir(dir);
// 			continue ;
// 		}
// 		res = _set_res(res, tmp);
// 		dirent = readdir(dir);
// 	}
// 	return (res);
// }

// static char	*_wildcard_to_str(char *str)
// {
// 	char		*res;
// 	DIR			*dir;
// 	t_wildcard	*wildcard;

// 	wildcard = (t_wildcard *)sp_malloc(sizeof(t_wildcard));
// 	wildcard->prefix = get_prefix(str);
// 	wildcard->suffix = get_suffix(str);
// 	dir = get_dir_pointer(wildcard);
// 	if (wildcard->prefix && ft_strchr(wildcard->prefix, '/') && !dir)
// 		return (NULL);
// 	else if (!dir)
// 		exit_error("\033[31mError: opendir(): Failed to open directory\n\033[0m");
// 	res = _convert_wildcard(dir, wildcard);
// 	closedir(dir);
// 	free(wildcard->prefix);
// 	free(wildcard->suffix);
// 	free(wildcard);
// 	return (res);
// }

// static char	*_convert_str(char *str)
// {
// 	char	**split;
// 	char	*res;
// 	char	*tmp;
// 	int		i;

// 	split = ft_split(str, ' ');
// 	if (!split)
// 		exit_error("\033[31mError: ft_split(): Failed to split string\n\033[0m");
// 	i = 0;
// 	while (split[i])
// 	{
// 		if (ft_strchr(split[i], '*'))
// 		{
// 			tmp = _wildcard_to_str(split[i]);
// 			if (tmp)
// 			{
// 				free(split[i]);
// 				split[i] = tmp;
// 			}
// 		}
// 		i++;
// 	}
// 	res = wildcard_join(split);
// 	free_dp((void **) split);
// 	return (res);
// }



static int _check_matched(char *wildcard, char dirent[])
{
    int flag = 0;

    if (*dirent == '\0')
    {
        while (*wildcard)
        {
            if (*wildcard != '*')
                return (0);
            wildcard++;
        }
        return (1);
    }
    while (*wildcard)
    {
        if (*wildcard == '*' && _check_matched(wildcard, dirent + 1))
            return (1);
        else if (*wildcard == *dirent && _check_matched(wildcard + 1, dirent + 1))
            return (1);
        else
            return (0) ;
        wildcard++;
    }
    return flag;
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
	ret = dp_malloc(sizeof(char *) * (total_len + 1));
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
		ret = dp_malloc(sizeof(char *) * 2);
		ret[0] = ft_strdup(path);
		ret[1] = NULL;
		return (ret);
	}
	if (!dir)
		return (NULL);
	if (*path_token[curr_depth] == '/')
		return (_get_matched_name(path_token, ft_strjoin(path, path_token[curr_depth]), curr_depth + 1, dir));
	_dirent = readdir(dir);
	while (_dirent)
	{
		if (!(ft_strchr(path_token[curr_depth], '*') && _dirent->d_name[0] == '.') \
			&& (path_token[curr_depth + 1] == NULL || (*path_token[curr_depth + 1] == '/' && _dirent->d_type == 4)) \
			&& _check_matched(path_token[curr_depth], _dirent->d_name))
		{
			matched_dir = ft_strjoin(path, _dirent->d_name);
			ret = _ft_dp_join(ret, _get_matched_name(path_token, matched_dir, curr_depth + 1, opendir(matched_dir)));
			free(matched_dir);
		}
		_dirent = readdir(dir);
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
			if (res)
				node->token->value = wildcard_join(res);
			printf("wildcard parse result: %s\n", node->token->value);
		}
		node = node->next;
		if (node == lst->header.next)
			break ;
	}
}
