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

size_t	is_pair_double_quotes(char *str)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (str[0] == '\"' && str[i])
	{
		if (str[i] == '\"')
			cnt++;
		i++;
	}
	if (cnt % 2 == 1 || cnt == 0)
		return (FALSE);
	return (TRUE);
}

size_t	is_pair_single_quotes(char *str)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (str[0] == '\'' && str[i])
	{
		if (str[i] == '\'')
			cnt++;
		i++;
	}
	if (cnt % 2 == 1 || cnt == 0)
		return (FALSE);
	return (TRUE);
}
