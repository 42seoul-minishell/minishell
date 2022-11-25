/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:03:25 by gimmingyu         #+#    #+#             */
/*   Updated: 2022/11/01 12:40:53 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	delete_item(t_ht_item *item)
{
	free(item->key);
	free(item->value);
	free(item);
}

void	delete_table(t_hashtable *table)
{
	size_t		idx;
	t_ht_item	*item;
	t_ht_item	*next;

	idx = -1;
	while (++idx < table->size)
	{
		item = table->items[idx];
		while (item)
		{
			next = item->next;
			delete_item(item);
			item = next;
		}
	}
	free(table->items);
	free(table);
}

static void	*_set_new_hashtable(t_hashtable *table, t_ht_item *item, t_ht_item *prev, size_t idx)
{
	t_ht_item	*tmp;

	if (!prev)
	{
		tmp = item->next;
		delete_item(item);
		table->items[idx] = tmp;
	}
	else
	{
		tmp = item->next;
		prev->next = tmp;
		delete_item(item);
	}
}

void	delete_item_by_key(t_hashtable *table, char *key)
{
	size_t		idx;
	t_ht_item	*item;
	t_ht_item	*prev;

	idx = hash_index(key, table->size);
	item = table->items[idx];
	while (item)
	{
		if (ft_strncmp(item->key, key, ft_strlen(key) + 1) == 0)
		{
			_set_new_hashtable(table, item, prev, idx);
			break;
		}
		prev = item;
		item = item->next;
	}
}
