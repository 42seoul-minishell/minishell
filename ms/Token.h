/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../../../include/minishell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:43:52 by bolee             #+#    #+#             */
/*   Updated: 2022/09/21 19:26:45 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

// 토큰의 타입
# define T_NULL 0
# define T_WORD 1
# define T_PIPE 2
# define T_REDIRECT 3
# define T_DOUBLE_QUOTES 4
# define T_SINGLE_QUOTES 5

# include "Utils/Standard.h"

/* token structure  */
typedef struct s_token
{
	int		type;
	char	*str;
}	t_token;

/* in Token.c */
// 토큰의 우선 순위를 비교한 결과를 반환하는 함수
int		compare_type(t_token *t1, t_token *t2);

// token 생성 함수
t_token	*make_token(char *str);
int		is_null(char *str);
int		is_pipe(char *str);
int		is_redirect(char *str);
int		is_double_quotes(char *str);
int		is_single_quotes(char *str);

#endif
