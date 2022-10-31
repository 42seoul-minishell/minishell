/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:20:57 by gimmingyu         #+#    #+#             */
/*   Updated: 2022/10/31 15:27:18 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

t_hashtable	*parse_env_to_hashtable(char **env)
{
	t_hashtable	*table;
	size_t		size;
	size_t		idx;
	char		*key;
	char		*value;

	size = 0;
	while (env[size])
		size++;
	table = create_hashtable(size * 2);
	idx = 0;
	while (idx < size)
	{
		key = get_key_from_env(env[idx]);
		value = get_value_from_env(env[idx++]);
		insert(create_ht_item(key, value), table);
		free(key);
		free(value);
	}
	return (table);
}
