/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:19:33 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/17 21:18:45 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minishell.h"

t_tType	verify_quote_token(char *str)
{
	if (is_have(str, '"') == TRUE)
	{
		if (is_pair_double_quotes(str) == FALSE)
			exit_on_error("minish: syntax error near unexpected token `\"");
		return (D_QUOTE);
	}
	if (is_have(str, '\'') == TRUE)
		if (is_pair_single_quotes(str) == FALSE)
			exit_on_error("minish: syntax error near unexpected token `\"");
	return (S_QUOTE);
}

t_tType	verify_bracket_token(char *str)
{
	if (*str == '(')
		exit_on_error("minish: syntax error near unexpected token `)'");
	str_parens(str, *str);
	return (BRACKET);
}

t_tType	verify_redirect_token(char *str)
{
	if (is_double_operator(str), *str == '<')
		return (HERE_DOC);
	if (is_double_operator(str), *str == '>')
		return (APPEND_RD);
	if (*str == '>')
		return (OUTPUT_RD);
	return (INPUT_RD);
}

t_tType	verify_command(char *str)
{
	return (CMD);
}

t_tType	verify_token(char *str)
{
	ssize_t	idx;
	char	*tmp;

	idx = -1;
	while (str[++idx])
	{
		while (str[idx] == ' ')
			idx++;
		if (ft_strchr("\'\"", str[idx]))
			return (verify_quote_token(str));
		else if (ft_strchr("()", str[idx]))
			return (verify_bracket_token(str));
		else if (ft_strchr("<>", str[idx]))
			return (verify_redirect_token(str));
		else
			return (verify_command(str));
	}
	printf("Something is wrong...\n");
	exit(1);
}
