/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:26:57 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:26:58 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static ssize_t	_get_operator_length(char *str)
{
	ssize_t	len;
	char	c;

	len = 1;
	c = *str;
	if (is_quote(str))
		while (*(str + len) != c)
			len++;
	else if (*str == '(' || *str == ')')
		return (1);
	else if (is_double_operator(str))
		return (2);
	else if (is_operator(str))
		return (1);
	return (len);
}

/* operator에 도달 시 호출. operator만 따로 담아서 넣는다 */
static void	_insert_helper(t_doubly_list *lst, char *str, \
								ssize_t *current, ssize_t *before)
{
	char	*beforeefore_op;
	char	*after_op;
	char	*trimmed;
	ssize_t	op_len;

	if (*current - *before >= 0)
	{
		beforeefore_op = (char *)sp_malloc(sizeof(char) * \
								(*current - *before + 1));
		ft_strlcpy(beforeefore_op, str + *before, *current - *before + 1);
		trimmed = ft_strtrim(beforeefore_op, " ");
		free(beforeefore_op);
		if (is_only_space(trimmed) == FALSE)
			safe_insert(lst, verify_token(trimmed), trimmed);
	}
	op_len = _get_operator_length(str + *current);
	after_op = (char *)sp_malloc(sizeof(char) * (op_len + 1));
	ft_strlcpy(after_op, str + *current, op_len + 1);
	trimmed = ft_strtrim(after_op, " ");
	free(after_op);
	if (is_only_space(trimmed) == FALSE)
		safe_insert(lst, verify_token(trimmed), trimmed);
	*current += op_len;
	*before = *current;
}

/* operator(', ")에 도달 시 호출. 현재 기준 이전과 그 다음 블록까지 lst에 넣는다 */
static void	_insert_helper_quote_case(t_doubly_list *lst, char *str, \
								ssize_t *current, ssize_t *before)
{
	char	*before_op;
	char	*after_op;
	char	*trimmed;
	ssize_t	op_len;

	before_op = (char *)sp_malloc(sizeof(char) * (*current - *before + 2));
	ft_strlcpy(before_op, str + *before, *current - *before + 1);
	trimmed = ft_strtrim(before_op, " ");
	if (!trimmed)
		exit_error("\033[31mError: ft_strtrim(): Failed to trim string\n\033[0m");
	free(before_op);
	if (is_only_space(trimmed) == FALSE)
		safe_insert(lst, verify_token(trimmed), trimmed);
	op_len = _get_operator_length(str + *current) + 1;
	after_op = (char *)sp_malloc(sizeof(char) * (op_len + 1));
	ft_strlcpy(after_op, str + *current, op_len + 1);
	*current += op_len;
	*before = *current;
	if (is_only_space(after_op) == FALSE)
		safe_insert(lst, verify_token(after_op), after_op);
}

static void	_make_token_list(t_doubly_list *lst, char *str)
{	
	ssize_t	current;
	ssize_t	before;
	ssize_t	len;

	current = 0;
	before = 0;
	len = ft_strlen(str);
	while (str[current] && current < len && before < len)
	{
		while (str[current] && !is_operator(str + current) \
			&& !is_quote(str + current))
			current++;
		if (is_quote(str + current))
			_insert_helper_quote_case(lst, str, &current, &before);
		else if (is_operator(str + current))
			_insert_helper(lst, str, &current, &before);
	}
	_insert_helper(lst, str, &current, &before);
}

void	tokenizer(t_doubly_list *lst, char *str)
{
	if (str[0] == '\0')
		return ;
	_make_token_list(lst, str);
	relocation_doubly_lst(lst);
}
