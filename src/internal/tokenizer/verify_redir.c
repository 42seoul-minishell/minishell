/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:53:58 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/19 00:38:03 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_tType	verify_input_redir(char *str)
{
	if (str[0] == '<' && str[1] && str[1] == str[0])
		return (HERE_DOC);
	if (str[0] == '<')
		return (INP_RDIR);
	exit_on_error("syntax error near unexpected token `>'");
	return (NONE);
}

t_tType	verify_output_redir(char *str)
{
	if (str[0] == '>' && str[1] && str[1] == str[0])
		return (APP_RDIR);
	if (str[0] == '>')
		return (OUT_RDIR);
	exit_on_error("syntax error near unexpected token `<'");
	return (NONE);
}
