/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:09:18 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/20 17:17:25 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

ssize_t	get_operator_length(char *str)
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
void	insert_helper(t_doubly_list *lst, char *str, ssize_t *c, ssize_t *b)
{
	char	*before_op;
	char	*after_op;
	char	*trimmed;
	ssize_t	op_len;

	if (*c - *b >= 0)
	{
		before_op = safe_malloc(*c - *b);
		ft_strlcpy(before_op, str + *b, *c - *b + 1);
		trimmed = ft_strtrim(before_op, " ");
		if (is_only_space(trimmed) == FALSE)
			safe_insert(lst, verify_token(trimmed), trimmed);
		free(before_op);
	}
	op_len = get_operator_length(str + *c);
	after_op = safe_malloc(op_len);
	ft_strlcpy(after_op, str + *c, op_len + 1);
	trimmed = ft_strtrim(before_op, " ");
	free(after_op);
	if (is_only_space(trimmed) == FALSE)
		safe_insert(lst, verify_token(trimmed), trimmed);
	*c += op_len;
	*b = *c;
}

/* operator에 도달 시 호출. 현재 기준 이전과 그 다음 블록까지 lst에 넣는다 */
void	insert_helper_quote_case(t_doubly_list *lst, char *str, \
								ssize_t *c, ssize_t *b)
{
	char	*before_op;
	char	*after_op;
	char	*trimmed;
	ssize_t	op_len;

	before_op = safe_malloc(*c - *b + 1);
	ft_strlcpy(before_op, str + *b, *c - *b + 1);
	trimmed = ft_strtrim(before_op, " ");
	free(before_op);
	if (is_only_space(trimmed) == FALSE)
		safe_insert(lst, verify_token(trimmed), trimmed);
	op_len = get_operator_length(str + *c) + 1;
	after_op = safe_malloc(op_len);
	ft_strlcpy(after_op, str + *c, op_len + 1);
	*c += op_len;
	*b = *c;
	if (is_only_space(after_op) == FALSE)
		safe_insert(lst, verify_token(after_op), after_op);
}

void	make_token_list(t_doubly_list *lst, char *str)
{	
	ssize_t	current;
	ssize_t	before;
	ssize_t	len;

	current = 0;
	before = 0;
	len = ft_strlen(str);
	while (str[current] && current < len && before < len)
	{
		while (!is_operator(str + current) && !is_quote(str + current))
			current++;
		if (is_quote(str + current))
			insert_helper_quote_case(lst, str, &current, &before);
		else if (is_operator(str + current))
			insert_helper(lst, str, &current, &before);
	}
	insert_helper(lst, str, &current, &before);
	printf("str + current = %s\n", str + current);
	printf("*(str + current) = %c\n", *(str + current));
	printf("current = %td\n", current);
}

void	tokenizer(t_doubly_list *lst, char *str)
{
	if (str[0] == '\0')
		return ;
	make_token_list(lst, str);
}
