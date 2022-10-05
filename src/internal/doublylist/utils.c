/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:35:19 by mingkim           #+#    #+#             */
/*   Updated: 2022/10/05 16:49:01 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	is_list_empty(t_doubly_list *lst)
{
	if (lst->len == 0)
		return (TRUE);
	return (FALSE);
}

void	display_list(t_doubly_list *lst)
{
	size_t			count;
	t_doubly_node	*node;

	if (!lst || is_list_empty(lst))
		return ;
	count = -1;
	node = lst->header.next;
	while (++count < lst->len - 1)
	{
		printf("doubly list node, index of %zd\n", count);
		printf("token value = %s\n", node->token->value);
		switch_type(node->token->type);
		node = node->next;
	}
}

/* 구현이 완료된 함수인지 확인해 주세욥 */
void	switch_type(t_type type)
{
	if (type == T_NULL)
		printf("token type = T_NULL\n");
	else if (type == T_WORD)
		printf("token type = T_WORD\n");
	else if (type == T_PIPE)
		printf("token type = T_PIPE\n");
	else if (type == T_REDIRECT)
		printf("token type = T_REDIRECT\n");
	else if (type == T_DOUBLE_QUOTES)
		printf("token type = T_DOUBLE_QUOTES\n");
}

t_doubly_node   *find_node(t_doubly_list *lst, char *str)
{
    t_doubly_node   *node;

	node = lst->header.next;
    while (node != NULL)
	{
		if (ft_strncmp(node->token->value, str, ft_strlen(node->token->value)) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}
