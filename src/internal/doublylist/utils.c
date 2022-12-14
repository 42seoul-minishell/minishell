/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:19:05 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:19:06 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	while (++count < lst->len)
	{
		printf("token value = %s\n", node->token->value);
		printf("token type = %d\n", node->token->type);
		node = node->next;
	}
}

t_doubly_node	*find_doubly_node(t_doubly_list *lst, char *str)
{
	t_doubly_node	*node;
	t_doubly_node	*tmp;

	if (is_list_empty(lst))
		exit(1);
	node = lst->header.next;
	if (node != NULL)
	{
		if (!ft_strncmp(node->token->value, str, ft_strlen(node->token->value)))
			return (node);
		tmp = node->next;
		while (tmp != node)
		{
			if (!ft_strncmp(tmp->token->value, \
			str, ft_strlen(tmp->token->value)))
				return (tmp);
			tmp = tmp->next;
		}
	}
	exit(1);
}
