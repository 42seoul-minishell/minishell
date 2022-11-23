/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:09:37 by mingkim           #+#    #+#             */
/*   Updated: 2022/10/18 14:31:04 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	builtin_export(char *key, char *value)
{
	size_t			idx;
	t_ht_item		*item;
	char			*tmp;

	tmp = search(g_global->envp, key);
	if (!tmp)
	{
		item = create_ht_item(key, value);
		if (!item)
			return (FALSE);
		hash_insert(item, g_global->envp);
		return (TRUE);
	}
	idx = hash_index(key, g_global->envp->size);
	item = g_global->envp->items[idx];
	while (item)
	{
		if (ft_strncmp(item->key, key, ft_strlen(key) + 1) == 0)
		{
			item->value = value;
			break ;
		}
		item = item->next;
	}
	return (TRUE);
}
