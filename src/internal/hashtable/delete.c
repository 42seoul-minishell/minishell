/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:03:25 by gimmingyu         #+#    #+#             */
/*   Updated: 2022/10/31 16:45:15 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

void	delete_item(t_ht_item *item)
{
	free(item->key);
	free(item->value);
	free(item);
}

void	delete_table(t_hashtable *table)
{
	size_t			idx;
	t_ht_item		*item;

	idx = -1;
	while (++idx < table->count)
	{
		item = table->items[idx];
		delete_item(item);
	}
	free(table->items);
	free(table);
}
