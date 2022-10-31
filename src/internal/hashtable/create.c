/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:06:11 by gimmingyu         #+#    #+#             */
/*   Updated: 2022/10/31 15:28:24 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

t_hashtable	*create_hashtable(size_t size)
{
	t_hashtable		*table;
	t_HashTableItem	**dict;
	size_t			idx;

	table = ft_calloc(1, sizeof(t_HashTableItem));
	dict = ft_calloc(size, sizeof(t_HashTableItem));
	table->dict = dict;
	table->size = size;
	idx = 0;
	while (idx < size)
		table->dict[idx++] = NULL;
	return (table);
}

t_HashTableItem	*create_ht_item(char *key, char *value)
{
	t_HashTableItem	*item;

	item = malloc(sizeof(t_HashTableItem));
	if (!item)
		return (NULL);
	item->key = malloc(ft_strlen(key) + 1);
	item->value = malloc(ft_strlen(value) + 1);
	ft_strlcpy(item->key, key, ft_strlen(key) + 1);
	ft_strlcpy(item->value, value, ft_strlen(value) + 1);
	return (item);
}
