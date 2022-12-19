/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:26:40 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:26:41 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_have(char *str, char sep)
{
	if (ft_strchr(str, sep))
		return (TRUE);
	return (FALSE);
}

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
			if (str[idx] == '"')
				continue ;
			return (FALSE);
		}
	}
	return (TRUE);
}

/* bracket 짝이 맞는지 확인 */
size_t	is_pair_bracket(char *str, char open, char close)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == open)
			cnt++;
		if (str[i] == close)
			cnt--;
		i++;
	}
	if (cnt != 0)
		return (FALSE);
	return (TRUE);
}

/* Double quote 짝이 맞는지 확인 */
size_t	is_pair_double_quotes(char *str)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == '"')
			cnt++;
		i++;
	}
	if (cnt % 2 == 1)
		return (FALSE);
	return (TRUE);
}

/* Single quote 짝이 맞는지 확인 */
size_t	is_pair_single_quotes(char *str)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			cnt++;
		i++;
	}
	if (cnt % 2 == 1)
		return (FALSE);
	return (TRUE);
}
