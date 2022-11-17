/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:35:19 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/17 21:18:34 by mingkim          ###   ########.fr       */
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
	while (++count < lst->len)
	{
		printf("doubly list node, index of %zd\n", count);
		printf("token value = %s\n", node->token->value);
		check_type(node->token->type);
		node = node->next;
	}
}

t_tType	check_type(t_tType type)
{
	if (type == NONE)
		return (NONE);
	else if (type == PIPE)
		return (PIPE);
	else if (type == CMD)
		return (CMD);
	else if (type == OPTION)
		return (OPTION);
	else if (type == D_QUOTE)
		return (S_QUOTE);
	else if (type == INPUT_RD)
		return (INPUT_RD);
	else if (type == OUTPUT_RD)
		return (OUTPUT_RD);
	else if (type == APPEND_RD)
		return (APPEND_RD);
	else if (type == HERE_DOC)
		return (BRACKET);
	else
		return (0);
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
