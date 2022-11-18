/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:06:13 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/18 17:13:43 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minishell.h"

int	is_double_operator(char *str)
{
	if (ft_strncmp(str, ">>", 2) == 0 || ft_strncmp(str, "<<", 2) == 0)
		return (TRUE);
	return (FALSE);
}

int	is_operator(char *str)
{
	if (*str == '|' || *str == '>' || *str == '<' || *str == '"')
		return (TRUE);
	if (is_double_operator(str))
		return (TRUE);
	return (FALSE);
}

t_tType	tree_node_type(int type)
{
	if (type == '|')
		return (PIPE);
	else if (type == '(' || type == ')')
		return (BRACKET);
	else
		return (NONE);
}

int	safe_insert(t_doubly_list *lst, t_tType type, char *str)
{
	t_token			*token;
	t_doubly_node	*node;

	token = create_token(type, str);
	node = create_doubly_node(token);
	insert_node(lst, node);
	return (TRUE);
}
