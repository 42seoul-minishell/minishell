/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:03:36 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/18 16:53:07 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	str_parens(char *str, int i)
{
	int	cnt;

	if (str[i] == ')')
		return (-1);
	i += 1;
	cnt = 1;
	while (cnt && str[i])
	{
		if (str[i] == '(')
			cnt += 1;
		else if (str[i] == ')')
			cnt -= 1;
		i++;
	}
	if (cnt > 0)
		return (0);
	else if (cnt < 0)
		return (-1);
	return (i);
}

int	is_have(char *str, char sep)
{
	if (ft_strchr(str, sep))
		return (TRUE);
	return (FALSE);
}
