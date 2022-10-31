/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:06:11 by gimmingyu         #+#    #+#             */
/*   Updated: 2022/10/31 16:48:37 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

t_hashtable	*create_hashtable(size_t size)
{
	t_hashtable		*table;
	t_ht_item		**items;
	size_t			idx;

	table = ft_calloc(1, sizeof(t_ht_item));
	items = ft_calloc(size, sizeof(t_ht_item));
	table->items = items;
	table->size = size;
	idx = 0;
	while (idx < size)
		table->items[idx++] = NULL;
	return (table);
}

t_ht_item	*create_ht_item(char *key, char *value)
{
	t_ht_item	*item;

	item = malloc(sizeof(t_ht_item));
	if (!item)
		return (NULL);
	item->key = malloc(ft_strlen(key) + 1);
	item->value = malloc(ft_strlen(value) + 1);
	ft_strlcpy(item->key, key, ft_strlen(key) + 1);
	ft_strlcpy(item->value, value, ft_strlen(value) + 1);
	return (item);
}
