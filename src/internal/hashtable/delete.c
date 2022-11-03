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
	size_t			idx;
	t_ht_item		*item;
	t_ht_item		*next;

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
