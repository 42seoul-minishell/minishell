/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:00:20 by bolee             #+#    #+#             */
/*   Updated: 2022/09/21 23:40:16 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
// 어휘 분석기
# define LEXER_H

# include "../../../include/minishell.h"

/* Tokens structure */
typedef struct s_tokens
{
	t_token			*token;
	struct s_tokens	*next;
}	t_tokens;

/* in Lexer.c */
/* 문자열을 입력 받아 토큰을 생성하는 함수 */ 
int			make_tokens(t_tokens **tokens, char *expr);

/* about tokens structure in Lexer.c */
t_tokens	*tokens_new(t_token *token);
t_tokens	*tokens_last(t_tokens *tokens);
void		tokens_add_back(t_tokens **token, t_tokens *new);

#endif
