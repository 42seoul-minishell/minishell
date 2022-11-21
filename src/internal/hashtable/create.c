/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:06:11 by gimmingyu         #+#    #+#             */
/*   Updated: 2022/11/17 20:27:36 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_hashtable	*create_hashtable(size_t size)
{
	t_hashtable	*table;
	t_ht_item	**items;
	size_t		idx;

	table = (t_hashtable *)sp_malloc(sizeof(t_hashtable));
	items = (t_ht_item **)dp_malloc(size * sizeof(t_ht_item *));
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

	item = (t_ht_item *)sp_malloc(sizeof(t_ht_item));
	item->key = (char *)sp_malloc(ft_strlen(key) + 1);
	item->value = (char *)sp_malloc(ft_strlen(value) + 1);
	ft_strlcpy(item->key, key, ft_strlen(key) + 1);
	ft_strlcpy(item->value, value, ft_strlen(value) + 1);
	return (item);
}
