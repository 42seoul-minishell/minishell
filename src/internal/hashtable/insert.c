/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:22:18 by gimmingyu         #+#    #+#             */
/*   Updated: 2022/10/31 19:33:21 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

void	hash_insert(t_ht_item *new_item, t_hashtable *table)
{
	size_t			hash;
	t_ht_item		*item;

	hash = hash_index(new_item->key, table->size);
	item = table->items[hash];
	if (!item)
	{
		table->items[hash] = new_item;
		table->count++;
		new_item->next = NULL;
		return ;
	}
	if (ft_strncmp(item->key, new_item->key, ft_strlen(new_item->key) + 1) == 0)
	{
		item->value = ft_strdup(new_item->value);
		delete_item(new_item);
		return ;
	}
	prevent_collision(table, hash, new_item);
}
