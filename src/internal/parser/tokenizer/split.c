/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:36:38 by bolee             #+#    #+#             */
/*   Updated: 2022/11/16 17:29:59 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minishell.h"

// static char	*get_prev(char *str, char sep)
// {
// 	size_t	idx;
// 	char	*ptr;

// 	idx = ft_strlen(str);
// 	while (idx--)
// 		if (str[idx] == sep)
// 			break ;
// 	ptr = (char *)malloc(sizeof(char) * idx);
// 	ft_strlcpy(ptr, str, idx);
// 	free(str);
// 	return (ptr);
// }

// int	split_quotes(t_doubly_list *lst, char *str)
// {
// 	ssize_t			idx;
// 	ssize_t			start;
// 	char			*prev;
// 	t_token			*token;
// 	t_doubly_node	*node;

// 	if (!str || is_valid(str, '"'))
// 		return (FALSE);
// 	start = 0;
// 	idx = -1;
// 	while (str[++idx])
// 	{
// 		if (str[idx] == '"')
// 		{
// 			prev = ft_substr(str, start, idx - start);
// 			start = idx + 1;
// 			if (str[idx - start + 1] == '"')
// 				token = create_token(T_DOUBLE_QUOTES, prev);
// 			else
// 				token = create_token(T_NULL, prev);
// 			node = create_doubly_node(token);
// 			insert_node(lst, node);
// 		}
// 	}
// 	ft_substr(str, start, ft_strlen(str));
// 	token = create_token(T_NULL, prev);
// 	node = create_doubly_node(token);
// 	insert_node(lst, node);
// 	return (TRUE);
// }

// void	split(t_doubly_list *lst, char *str, char sep)
// {
// 	char			*next;
// 	char			*prev;
// 	t_token			*token;
// 	t_doubly_node	*node;

// 	next = ft_strdup(ft_strrchr(str, sep));
// 	if (next == NULL)
// 	{
// 		token = create_token(T_NULL, str);
// 		node = create_doubly_node(token);
// 		insert_node(lst, node);
// 		return ;
// 	}
// 	token = create_token(T_NULL, next);
// 	node = create_doubly_node(token);
// 	insert_node(lst, node);
// 	prev = get_prev(str, sep);
// 	split(lst, prev, sep);
// }
