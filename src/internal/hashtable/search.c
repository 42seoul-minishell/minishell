/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:25:14 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:25:17 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search(t_hashtable *table, char *key)
{
	size_t		idx;
	t_ht_item	*item;

	idx = hash_index(key, table->size);
	item = table->items[idx];
	while (item)
	{
		if (ft_strncmp(item->key, key, ft_strlen(key) + 1) == 0)
			return (item->value);
		item = item->next;
	}
	return (NULL);
}
