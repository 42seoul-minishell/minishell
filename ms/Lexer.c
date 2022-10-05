/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:00:34 by bolee             #+#    #+#             */
/*   Updated: 2022/09/21 23:33:12 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.h"

// tokens 전체 free 함수
static void	tokens_clear(t_tokens **tokens)
{
	t_tokens	*token;
	t_tokens	*tmp;

	token = *tokens;
	while (token)
	{
		tmp = token;
		token = token->next;
		free(tmp);
	}
	*tokens = NULL;
}

int	make_tokens(t_tokens **tokens, char *expr)
{
	int			i;
	t_token		*token;
	t_tokens	*new;
	char		**split;

	// 이전에 생성했던 토큰 제거
	if (*tokens != NULL)
		tokens_clear(tokens);
	split = ft_split(expr, ' ');
	i = 0;
	while (split[i])
	{
		token = make_token(split[i]);
		if (token == NULL)
			return (0);
		new = (t_tokens *)malloc(sizeof(t_tokens));
		if (new == NULL)
			return (0);
		new->token = token;
		new->next = NULL;		
		tokens_add_back(tokens, new);
		i++;
	}
	return (1);
}

t_tokens	*tokens_new(t_token *token)
{
	t_tokens	*new_lst;

	new_lst = (t_tokens *)malloc(sizeof(t_tokens));
	if (!new_lst)
		return (NULL);
	new_lst->token = token;
	new_lst->next = NULL;
	return (new_lst);
}

t_tokens	*tokens_last(t_tokens *tokens)
{
	if (!tokens)
		return (NULL);
	while (tokens->next)
		tokens = tokens->next;
	return (tokens);
}

void	tokens_add_back(t_tokens **tokens, t_tokens *new)
{
	t_tokens	*tmp;

	if (*tokens)
	{
		tmp = tokens_last(*tokens);
		tmp->next = new;
	}
	else
		*tokens = new;
}
