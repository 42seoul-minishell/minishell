/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:23:58 by bolee             #+#    #+#             */
/*   Updated: 2022/12/28 19:23:59 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_bintree_type(int type)
{
	if (type == OR)
		return (TN_OR);
	else if (type == AND)
		return (TN_AND);
	else if (type == PIPE)
		return (TN_PIPE);
	else if (type >= INP_RDIR && type <= HERE_DOC)
		return (TN_RDIR);
	else if (type == BRACKET)
		return (TN_BRACKET);
	else
		return (TN_WORD);
}
