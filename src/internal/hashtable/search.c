/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:39:53 by gimmingyu         #+#    #+#             */
/*   Updated: 2022/11/17 20:28:09 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*search(t_hashtable *table, char *key)
{
	size_t		idx;
	t_ht_item	*item;

	idx = hash_index(key, table->size);
	item = table->items[idx];
	while (item)
	{
		if (ft_strncmp(item->key, key, ft_strlen(key) + 1) == 0)
			return (item->value);
		item = item->next;
	}
	return (NULL);
}
