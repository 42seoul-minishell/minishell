/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_brackets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:05:42 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/18 17:13:55 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minishell.h"

t_tType	verify_bracket(char *str)
{
	ssize_t	idx;

	if (str[0] != '(')
		exit_on_error("FUCK YOU");
	idx = 0;
	if (str[++idx])
	{
		while (ft_strchr("()", str[idx]))
			idx++;
		if (str[idx] == ')')
			return (BRACKET);
		exit_on_error("FUCK YOU TWICE");
	}
	exit_on_error("FUCK YOU AGAIN");
	return (NONE);
}
