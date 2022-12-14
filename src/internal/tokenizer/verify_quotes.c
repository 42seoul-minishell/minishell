/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:27:30 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:27:31 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tType	verify_double_quote(char *str)
{
	ssize_t	idx;

	idx = 0;
	while (str[++idx])
		if (str[idx] == '\"')
			return (D_QUOTE);
	return (CMD);
}

t_tType	verify_single_quote(char *str)
{
	ssize_t	idx;

	idx = 0;
	while (str[++idx])
		if (str[idx] == '\'')
			return (S_QUOTE);
	return (CMD);
}
