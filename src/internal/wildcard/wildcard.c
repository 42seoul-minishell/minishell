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

static void	_next(t_wildcard *wc, t_list *lst, int curr_depth);

static void	_destroy_wildcard(t_wildcard *wc)
{
	free_dp((void **)wc->path_token);
	ft_lstclear(&wc->lst.next, free);
}

static int	_check_recur(t_wildcard *wc, int curr_depth, \
	char d_name[], unsigned char type)
{
	if (*wc->path_token[curr_depth] == '/')
		return (1);
	if (!(ft_strchr(wc->path_token[curr_depth], '*') && d_name[0] == '.') \
		&& (wc->path_token[curr_depth + 1] == NULL \
		|| (*wc->path_token[curr_depth + 1] == '/' && type == 4)) \
		&& check_matched(wc->path_token[curr_depth], d_name))
		return (1);
	return (0);
}

static void	_find_matched(t_wildcard *wc, char *path, \
	int curr_depth, DIR *dir)
{
	struct dirent	*_dirent;
	t_list			lst;

	ft_memset(&lst, 0, sizeof(t_list));
	if (!wc->path_token[curr_depth] && ++wc->lst_size)
		ft_lstadd_back(&wc->lst.next, ft_lstnew((void *)ft_strdup(path)));
	else if (*wc->path_token[curr_depth] == '/')
		lstinsort(&lst, ft_lstnew(ft_strjoin(path, "/")), ft_strncmp);
	else
	{
		_dirent = readdir(dir);
		while (_dirent)
		{
			if (_check_recur(wc, curr_depth, _dirent->d_name, _dirent->d_type))
				lstinsort(&lst, \
					ft_lstnew(ft_strjoin(path, _dirent->d_name)), ft_strncmp);
			_dirent = readdir(dir);
		}
	}
	if (dir)
		closedir(dir);
	_next(wc, &lst, curr_depth);
}

static void	_next(t_wildcard *wc, t_list *lst, int curr_depth)
{
	t_list	*node;

	node = lst;
	while (node->next)
	{
		_find_matched(wc, (char *)node->next->content, curr_depth + 1,
			opendir((char *)node->next->content));
		node = node->next;
	}
	ft_lstclear(&lst->next, free);
	lst->next = NULL;
}

void	wildcard(t_doubly_list *lst)
{
	t_wildcard		wc;
	t_doubly_node	*node;
	DIR				*dir;

	node = lst->header.next;
	while (node)
	{
		if (ft_strchr(node->token->value, '*'))
		{
			ft_memset(&wc, 0, sizeof(t_wildcard));
			wc.token_value = ft_strdup(node->token->value);
			wc.path_token = ft_split(node->token->value, '/', 1);
			if (wc.path_token[0][0] == '/')
				dir = opendir("/");
			else
				dir = opendir(".");
			_find_matched(&wc, "", 0, dir);
			free(node->token->value);
			node->token->value = wildcard_join(&wc);
			_destroy_wildcard(&wc);
		}
		node = node->next;
		if (node == lst->header.next)
			break ;
	}
}
