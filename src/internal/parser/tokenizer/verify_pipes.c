/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:05:42 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/18 17:14:24 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minishell.h"

t_tType	verify_pipe(char *str)
{
	if (str[0] == '|' && str[1] && str[1] == str[0])
		return (OR);
	if (str[0] == '|')
		return (PIPE);
	exit_on_error("FUCK YOU");
	return (NONE);
}
