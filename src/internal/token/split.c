/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:12:00 by bolee             #+#    #+#             */
/*   Updated: 2022/11/02 17:12:01 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

static char	*get_prev(char *str, char sep)
{
	size_t	idx;
	char	*ptr;

	idx = ft_strlen(str);
	while (idx--)
		if (str[idx] == sep)
			break;
	ptr = (char *)malloc(sizeof(char) * idx);
	ft_strlcpy(ptr, str, idx);
	free(str);
	return (ptr);
}

void	split(t_doubly_list *lst, char *str, char sep)
{
	char			*next;
	char			*prev;
	t_token			*token;
	t_doubly_node	*node;

	next = ft_strdup(ft_strrchr(str, sep));
	if (next == NULL)
	{
		token = create_token(T_NULL, str);
		node = create_doubly_node(token);
		insert_node(lst, node);
		return ;
	}
	token = create_token(T_NULL, next);
	node = create_doubly_node(token);
	insert_node(lst, node);
	prev = get_prev(str, sep);
	split(lst, prev, sep);
}
