/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:39:53 by gimmingyu         #+#    #+#             */
/*   Updated: 2022/10/31 16:45:17 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

char	*search(t_hashtable *table, char *key)
{
	size_t			idx;
	t_ht_item		*item;

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
