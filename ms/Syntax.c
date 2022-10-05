/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:58:13 by bolee             #+#    #+#             */
/*   Updated: 2022/09/27 21:58:14 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Syntax.h"

void	syntax_pipeline(t_tokens *tokens)
{
	syntax_cmd(tokens);
	if (tokens->token->type == T_PIPE)
		syntax_pipeline(tokens);
}

void	syntax_cmd(t_tokens *tokens)
{
	syntax_simple_cmd(tokens);
	if (tokens->token->type == T_REDIRECT)
		syntax_redirects(tokens);
}

void	syntax_redirects(t_tokens *tokens)
{
	syntax_io_redirect(tokens);
	if (tokens->token->type == T_REDIRECT)
		syntax_redirects(tokens);
}

int	syntax_io_redirect(t_tokens *tokens)
{
	if (tokens->token->type == T_REDIRECT && \
        tokens->next->token->type == T_WORD)
		return (1);
	return (0);
}

int syntax_simple_cmd(t_tokens *tokens)
{
	if (tokens->token->type == T_WORD && \
        tokens->next->token->type == T_WORD)
			return (1);
	return (0);
}
