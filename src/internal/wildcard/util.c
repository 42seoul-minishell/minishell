/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:28:03 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:28:03 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lstinsort(t_list *lst, t_list *new_lst, \
	int (*cmp)(const char *p1, const char *p2))
{
	t_list	*node;

	node = lst;
	while ((node && node->next) \
		&& cmp(node->next->content, new_lst->content) < 0)
		node = node->next;
	new_lst->next = node->next;
	node->next = new_lst;
}

int	check_matched(char *wildcard, char dirent[])
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
	if ((*wildcard == *dirent) && check_matched(wildcard + 1, dirent + 1))
		return (1);
	if (*wildcard == '*')
		return (check_matched(wildcard + 1, dirent) \
			|| check_matched(wildcard, dirent + 1));
	return (0);
}

char	*wildcard_join(t_wildcard *wc)
{
	size_t	total_len;
	t_list	*node;
	char	*res;

	total_len = 0;
	node = wc->lst.next;
	while (node)
	{
		total_len += ft_strlen((char *)node->content);
		node = node->next;
	}
	total_len += wc->lst_size;
	res = (char *)ft_malloc(total_len + 1);
	if (!res || total_len == 0)
		return (wc->token_value);
	ft_memset((void *)res, 0, total_len + 1);
	node = wc->lst.next;
	while (node)
	{
		ft_strlcat(res, node->content, total_len + 1);
		if (node->next)
			ft_strlcat(res, " ", total_len + 1);
		node = node->next;
	}
	return (res);
}
