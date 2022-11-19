/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:07:19 by gimmingyu         #+#    #+#             */
/*   Updated: 2022/11/19 14:08:05 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*safe_malloc(size_t idx)
{
	char	*ret;

	ret = malloc(sizeof(char) * idx + 1);
	if (!ret)
		exit_on_error("memory allocate error\n");
	return (ret);
}

int	safe_insert(t_doubly_list *lst, t_tType type, char *str)
{
	t_token			*token;
	t_doubly_node	*node;

	token = create_token(type, str);
	node = create_doubly_node(token);
	insert_node(lst, node);
	return (TRUE);
}