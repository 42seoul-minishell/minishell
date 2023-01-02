/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:23:58 by bolee             #+#    #+#             */
/*   Updated: 2022/12/28 19:23:59 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_ctrl_oper(t_list *token_list)
{
	t_token *token;

	token = (t_token *)token_list->content;
	if (token->type == OR)
		return (TN_OR);
	else if (token->type == AND)
		return (TN_AND);
	else if (token->type == PIPE)
		return (TN_PIPE);
	return (TN_NONE);
}

int set_bintree_type(t_list *token_list)
{
	t_token *token;
	int flag;

	flag = 0;
	while (token_list)
	{
		token = (t_token *)token_list->content;
		if (token->type == BRACKET)
		{
			flag++;
			continue;
		}
		if (flag % 2 == 0 && token->type >= INP_RDIR && token->type < HERE_DOC)
			return (TN_RDIR);
		else if (flag % 2 == 0 && token->type == HERE_DOC)
			return (TN_HEREDOC);
		token_list = token_list->next;
	}
	if (flag != 0)
		return (TN_BRACKET);
	return (TN_WORD);
}
