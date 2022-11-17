/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:06:13 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/17 17:01:59 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	pass_space(char *str)
{
	while (*str == ' ')
		str++;
}

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

t_tType	type_casting(char *str)
{
	if (*str == '"')
		return (T_DOUBLE_QUOTES);
	else if (*str == '|')
		return (T_PIPE);
	else if (*str == '<' || *str == '>')
		return (T_REDIRECT);
	else if (*str == '(' || *str == ')')
		return (T_BRACKET);
	return (T_CMD);
}

int	safe_insert(t_doubly_list *lst, t_tType type, char *str)
{
	t_token			*token;
	t_doubly_node	*node;

	token = create_token(type, str);
	if (!token)
		return (FALSE);
	node = create_doubly_node(token);
	if (!node)
		return (FALSE);
	insert_node(lst, node);
	return (TRUE);
}
