/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:29:30 by bolee             #+#    #+#             */
/*   Updated: 2023/01/03 14:29:31 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	relocate_token_list(t_list **token_list)
{
	t_list	*tmp;
	t_list	*cmd_lst;
	t_list	*redir_lst;

	cmd_lst = NULL;
	redir_lst = NULL;
	while (*token_list)
	{
		tmp = *token_list;
		if (((t_token *)(*token_list)->content)->type >= INP_RDIR && \
				((t_token *)(*token_list)->content)->type <= HERE_DOC)
		{
			*token_list = (*token_list)->next->next;
			tmp->next->next = NULL;
			ft_lstadd_back(&redir_lst, tmp);
		}
		else
		{
			*token_list = (*token_list)->next;
			tmp->next = NULL;
			ft_lstadd_back(&cmd_lst, tmp);
		}
	}
	ft_lstadd_back(&cmd_lst, redir_lst);
	*token_list = cmd_lst;
}

static void	_append_token_list(t_list **token_list, t_doubly_node **node)
{
	t_token	*token;

	token = create_token((*node)->token->type, \
							ft_strdup((*node)->token->value));
	ft_lstadd_back(token_list, ft_lstnew((void *)token));
	*node = (*node)->next;
}

t_list	*set_token_list(t_doubly_list *lst, t_doubly_node **node)
{
	t_list	*token_list;
	t_tType	token_type;

	token_list = NULL;
	if ((*node)->token->type >= OR && (*node)->token->type <= PIPE)
	{
		_append_token_list(&token_list, node);
		return (token_list);
	}
	while (*node)
	{
		token_type = (*node)->token->type;
		if (token_type >= OR && token_type <= PIPE)
			break ;
		_append_token_list(&token_list, node);
		if (*node == lst->header.next)
			break ;
	}
	return (token_list);
}
