/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:17:33 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/19 00:38:03 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	_is_valid_next_token(t_doubly_node *cur, t_doubly_node *next)
{
	int	cur_type;
	int	next_type;

	cur_type = cur->token->type;
	next_type = next->token->type;
	if ((cur_type == CMD && next_type == BRACKET) \
		|| (cur_type == BRACKET && next_type == CMD) \
		|| (cur_type == BRACKET && next_type == BRACKET))
		return (FALSE);
	if ((cur_type >= INP_RDIR && cur_type <= HERE_DOC) \
		&& !(next_type >= CMD && next_type <= S_QUOTE))
		return (FALSE);
	if ((cur_type >= OR && cur_type <= PIPE) \
		&& (next_type >= OR && next_type <= PIPE))
		return (FALSE);
	return (TRUE);
}

static int	_is_valid_tokens(t_doubly_list *lst)
{
	t_doubly_node	*cur_node;
	t_doubly_node	*next_node;

	cur_node = lst->header.next;
	while (cur_node != lst->header.prev)
	{
		next_node = cur_node->next;
		if (_is_valid_next_token(cur_node, next_node) == FALSE)
		{
			if (cur_node->token->type >= INP_RDIR &&
				cur_node->token->type <= HERE_DOC)
				exit_on_error(SYNTAX_ERR);
			else
				exit_on_error(SYNTAX_ERR);
			return (FALSE);
		}
		cur_node = cur_node->next;
	}
	if (!(cur_node->token->type >= CMD \
		&& cur_node->token->type <= S_QUOTE) \
		&& cur_node->token->type != BRACKET)
		exit_on_error(SYNTAX_ERR);
	return (TRUE);
}

void	syntax(t_doubly_list *lst)
{
	t_doubly_node	*node;

	if (!lst || !lst->len)
		exit(1);
	node = lst->header.next;
	if (node->token->type == AND || node->token->type == OR ||
		node->token->type == PIPE)
		exit_on_error(SYNTAX_ERR);
	if (!_is_valid_tokens(lst))
		exit_on_error(SYNTAX_ERR);
	set_bintree(lst, lst->header.next);
}
