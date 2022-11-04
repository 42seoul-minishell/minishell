/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:09:18 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/02 14:10:52 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	is_have(char *str, char sep)
{
	if (ft_strchr(str, sep))
		return (TRUE);
	return (FALSE);
}

static size_t	is_pair_double_quotes(char *str)
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

static size_t	is_pair_bracket(char *str, char open, char close)
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

void	tokenizer(t_doubly_list *lst, char *str)
{
	char	*tmp;

	if (str[0] == '\0')
		return ;
	while (*str == ' ')
		str++;
	// if (is_have(str, '"') && is_pair_double_quotes(str, '"'))
	// {
	// 	while (is_have(str, '"'))
	// 	{
	// 		tmp = extract_from_str(&str, '"');
	// 	}
	// }
	// if (is_have(str, '|'))
	// {
	// 	while (is_have(str, '|'))
	// 	{
	// 		tmp = extract_from_str(&str, '|');
	// 	}
	// }
	// if (is_have('(') && is_pair_bracket(str, '(', ')'))
	// {
	// 	while (is_have(str, '('))
	// 	{
	// 		tmp = extract_brackets(&str, '(', ')');
	// 	}
	// }
}
