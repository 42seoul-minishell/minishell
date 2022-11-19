/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:52:53 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/19 00:38:03 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_tType	verify_double_quote(char *str)
{
	ssize_t	idx;

	idx = 0;
	while (str[++idx])
		if (str[idx] == '\"')
			return (D_QUOTE);
	exit_on_error("minish: syntax error near unexpected token `\"'");
	return (NONE);
}

t_tType	verify_single_quote(char *str)
{
	ssize_t	idx;

	idx = 0;
	while (str[++idx])
		if (str[idx] == '\'')
			return (S_QUOTE);
	exit_on_error("minish: syntax error near unexpected token `''");
	return (NONE);
}