/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:38:21 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:22:08 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void	_unset_hashtable(t_hashtable *table, t_ht_item *item, \
									t_ht_item *prev, size_t idx)
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

	if (search(table, key))
	{
		idx = hash_index(key, table->size);
		item = table->items[idx];
		prev = NULL;
		while (item)
		{
			if (ft_strncmp(item->key, key, ft_strlen(key) + 1) == 0)
			{
				_unset_hashtable(table, item, prev, idx);
				break ;
			}
			prev = item;
			item = item->next;
		}
	}
}
