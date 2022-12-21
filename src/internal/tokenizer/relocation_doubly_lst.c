/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reloction_doubly_lst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:15:54 by bolee             #+#    #+#             */
/*   Updated: 2022/12/19 18:15:57 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static t_doubly_node	*_link_lst(t_doubly_list *lst, t_doubly_node *node, \
										t_doubly_node *curr)
{
	t_doubly_node	*tmp;

	if (lst->len == 1)
	{
		curr->prev = curr->next;
		curr->next->next = curr;
		lst->header.next = curr;
		lst->header.prev = curr->next;
		release_doubly_node(node);
		return (curr->next);
	}
	tmp = node;
	node = curr;
	if (tmp == lst->header.next)
		lst->header.next = node;
	node->prev = tmp->prev;
	tmp->prev->next = node;
	while (node->next)
		node = node->next;
	if (tmp == lst->header.prev)
		lst->header.prev = node;
	node->next = tmp->next;
	tmp->next->prev = node;
	release_doubly_node(tmp);
	return (node);
}

static t_doubly_node	*_split_doubly_node(t_doubly_list *lst, \
												t_doubly_node *node)
{
	int				i;
	char			**split;
	t_doubly_node	*curr;
	t_doubly_node	*tmp;

	split = ft_split(node->token->value, ' ', 0);
	i = 0;
	while (split[i])
	{
		if (i == 0)
		{
			curr = create_doubly_node(create_token(CMD, ft_strdup(split[i])));
			tmp = curr;
			i++;
			continue ;
		}
		tmp->next = create_doubly_node(create_token(CMD, ft_strdup(split[i])));
		tmp->next->prev = tmp;
		tmp = tmp->next;
		i++;
	}
	lst->len += i - 1;
	free_dp((void **) split);
	return (_link_lst(lst, node, curr));
}

void	relocation_doubly_lst(t_doubly_list *lst)
{
	t_doubly_node	*tmp;

	tmp = lst->header.next;
	while (1)
	{
		if (tmp->token->type == CMD && ft_strchr(tmp->token->value, ' '))
			tmp = _split_doubly_node(lst, tmp);
		if (tmp == lst->header.prev)
			break ;
		tmp = tmp->next;
	}
}
