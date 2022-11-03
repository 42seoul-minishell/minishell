/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:04:53 by mingkim           #+#    #+#             */
/*   Updated: 2022/10/18 13:15:27 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	_display_env_list(t_doubly_list *lst)
{
	size_t			count;
	t_doubly_node	*node;

	if (!lst || is_list_empty(lst))
		return ;
	count = -1;
	node = lst->header.next;
	while (++count < lst->len)
	{
		printf("%s\n", node->token->value);
		node = node->next;
	}
}

// env 명령은 환경변수의 목록을 출력해줌.
void	builtin_env(t_doubly_list *lst)
{
	_display_env_list(lst);
}
