/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_brackets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:27:18 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:27:19 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_tType	verify_bracket(char *str)
{
	ssize_t	idx;

	if (str[0] != '(')
		exit_error("FUCK YOU");
	idx = 0;
	if (str[++idx])
	{
		while (ft_strchr("()", str[idx]))
			idx++;
		if (str[idx] == ')')
			return (BRACKET);
		exit_error("FUCK YOU TWICE");
	}
	exit_error("FUCK YOU AGAIN");
	return (NONE);
}
