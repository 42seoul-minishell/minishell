/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:19:33 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/20 16:48:53 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_tType	verify_token(char *str)
{
	ssize_t	idx;

	idx = -1;
	while (str[++idx])
	{
		while (str[idx] == ' ' || str[idx] == '\t')
			idx++;
		if (ft_strchr("\'", str[idx]))
			return (verify_single_quote(str + idx));
		else if (ft_strchr("\"", str[idx]))
			return (verify_double_quote(str + idx));
		else if (ft_strchr("()", str[idx]))
			return (BRACKET);
		else if (str[idx] == '<')
			return (verify_input_redir(str + idx));
		else if (str[idx] == '>')
			return (verify_output_redir(str + idx));
		else if (str[idx] == '|')
			return (verify_pipe(str + idx));
		else if (str[idx] == '&' && str[idx + 1] && str[idx + 1] == str[idx])
			return (AND);
	}
	return (CMD);
}
