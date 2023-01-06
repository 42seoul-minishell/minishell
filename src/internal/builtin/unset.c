/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:58:23 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:18:13 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_unset(t_list *lst)
{
	t_token	*token;

	while (lst)
	{
		token = (t_token *)lst->content;
		delete_item_by_key(g_global.envp, token->value);
		lst = lst->next;
	}
}
