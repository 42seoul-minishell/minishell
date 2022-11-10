/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:09:18 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/09 21:19:52 by mingkim          ###   ########.fr       */
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

// while 돌면서 node로 감싸서 넣어주는 함수 실행
void	insert_token(t_doubly_list *lst, char **splited)
{
	size_t			idx;
	t_type			type;

	idx = -1;
	while (splited[++idx])
	{
		type = type_casting(splited[idx]);
		if (type == T_DOUBLE_QUOTES)
		{
			idx++;
			while (type_casting(splited[idx]) != T_DOUBLE_QUOTES)
				safe_insert(lst, T_DOUBLE_QUOTES, splited[idx++]);
			idx++;
			continue ;
		}
		safe_insert(lst, type, splited[idx]);
	}
}

void	tokenizer(t_doubly_list *lst, char *str)
{
	char	*tmp;
	char	**splited;

	if (str[0] == '\0')
		return ;
	pass_space(str);
	if ((is_have(str, '"') == TRUE && is_pair_double_quotes(str) == FALSE) || \
		(is_have(str, '(') == TRUE && is_pair_bracket(str, '(', ')') == FALSE))
		exit(1);
	tmp = make_clean_sentence(str);
	check_single_pointer((void *) tmp);
	splited = ft_split(tmp, ' ');
	check_double_pointer((void **) splited);
	insert_token(lst, splited);
}
