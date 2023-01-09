/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:09:00 by bolee             #+#    #+#             */
/*   Updated: 2022/12/28 16:09:01 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_value(t_hashtable *table, char *key, char *value)
{
	size_t		idx;
	t_ht_item	*item;

	idx = hash_index(key, table->size);
	item = table->items[idx];
	while (item)
	{
		if (ft_strcmp(item->key, key) == 0)
		{
			free(item->value);
			item->value = value;
			break ;
		}
		item = item->next;
	}
}
