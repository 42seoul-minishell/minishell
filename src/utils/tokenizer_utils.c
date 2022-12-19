/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:28:34 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:28:36 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	safe_insert(t_doubly_list *lst, t_tType type, char *str)
{
	t_token			*token;
	t_doubly_node	*node;

	token = create_token(type, str);
	node = create_doubly_node(token);
	insert_node(lst, node);
	return (TRUE);
}

int	is_only_space(char *str)
{
	ssize_t	idx;

	idx = -1;
	while (str[++idx])
		if (str[idx] != ' ')
			return (FALSE);
	free(str);
	return (TRUE);
}
