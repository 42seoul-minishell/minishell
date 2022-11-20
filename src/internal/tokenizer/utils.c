/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:06:13 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/20 16:35:14 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	is_quote(char *str)
{
	if (*str == '\'' || *str == '\"')
		return (TRUE);
	return (FALSE);
}

int	is_operator(char *str)
{
	if (*str == '|' || *str == '>' || *str == '<' \
			|| *str == '(' || *str == ')')
		return (TRUE);
	return (FALSE);
}

int	is_double_operator(char *str)
{
	if (ft_strncmp(str, ">>", 2) == 0 || ft_strncmp(str, "<<", 2) == 0)
		return (TRUE);
	return (FALSE);
}

void	white_to_space(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\v' || str[i] == '\r')
			str[i] = ' ';
		i++;
	}
}
