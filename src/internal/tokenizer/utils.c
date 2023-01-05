/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:27:02 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:27:03 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static ssize_t	_get_bracket_length(char *str)
{
	ssize_t	i;
	ssize_t	cnt;

	i = 0;
	cnt = 1;
	while (*(str + i + 1))
	{
		if (*(str + i + 1) == '(')
			cnt++;
		else if (*(str + i + 1) == ')')
			cnt--;
		else if (cnt == 0)
			break ;
		i++;
	}
	if (cnt == 0)
		return (i + 2);
	return (1);
}

ssize_t	get_operator_length(char *str)
{
	ssize_t	len;
	char	c;

	len = 1;
	c = *str;
	if (is_quote(str))
		while (*(str + len) != c)
			len++;
	else if (*str == '(')
		return (_get_bracket_length(str));
	else if (*str == ')')
		return (1);
	else if (is_double_operator(str))
		return (2);
	else if (is_operator(str))
		return (1);
	return (len);
}

int	is_quote(char *str)
{
	if (*str == '\'' || *str == '\"')
		return (TRUE);
	return (FALSE);
}

int	is_operator(char *str)
{
	if (*str == '|' || *str == '>' || *str == '<' \
		|| *str == '(' || *str == ')' || *str == '&')
		return (TRUE);
	return (FALSE);
}

int	is_double_operator(char *str)
{
	if (ft_strncmp(str, ">>", 2) == 0 || ft_strncmp(str, "<<", 2) == 0)
		return (TRUE);
	if (ft_strncmp(str, "||", 2) == 0 || ft_strncmp(str, "&&", 2) == 0)
		return (TRUE);
	return (FALSE);
}
