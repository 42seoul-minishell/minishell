/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:27:39 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:27:40 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tType	verify_input_redir(char *str)
{
	if (str[0] == '<' && str[1] && str[1] == str[0])
		return (HERE_DOC);
	if (str[0] == '<')
		return (INP_RDIR);
	syntax_error("<");
	return (NONE);
}

t_tType	verify_output_redir(char *str)
{
	if (str[0] == '>' && str[1] && str[1] == str[0])
		return (APP_RDIR);
	if (str[0] == '>')
		return (OUT_RDIR);
	syntax_error(">");
	return (NONE);
}
