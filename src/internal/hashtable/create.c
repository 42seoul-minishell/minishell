/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:21:05 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:23:34 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_hashtable	*create_hashtable(size_t size)
{
	t_hashtable	*table;
	t_ht_item	**items;
	size_t		idx;

	table = (t_hashtable *)ft_malloc(sizeof(t_hashtable));
	items = (t_ht_item **)ft_malloc(size * sizeof(t_ht_item *));
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

	item = (t_ht_item *)ft_malloc(sizeof(t_ht_item));
	item->key = (char *)ft_malloc(ft_strlen(key) + 1);
	item->value = (char *)ft_malloc(ft_strlen(value) + 1);
	ft_strlcpy(item->key, key, ft_strlen(key) + 1);
	ft_strlcpy(item->value, value, ft_strlen(value) + 1);
	return (item);
}
