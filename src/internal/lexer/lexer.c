/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:17:33 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/10 21:06:48 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/* 연산자 앞뒤로 스페이스바가 있는지 확인 */
int	is_space_around_operator(char *str)
{
	size_t	idx;

	idx = -1;
	while (str[++idx])
	{
		if (is_operator(str + idx) == TRUE)
		{
			if (str[idx + 1] == ' ')
				continue ;
			if (str[idx + 1] == str[idx])
				continue ;
			return (FALSE);
		}
	}
	return (TRUE);
}

/* 명령어 순서 확인 */
/* 존재하는 명령어인지 확인 */
/*  */

void	lexer(t_doubly_list *lst, char *str)
{
	display_list(lst);
	if (is_space_around_operator(str) == FALSE)
		printf("FALSE");
}
