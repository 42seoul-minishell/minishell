/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:20:57 by gimmingyu         #+#    #+#             */
/*   Updated: 2022/10/31 18:30:44 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

size_t	hash_index(char *key, size_t size)
{
	size_t	hash;
	size_t	idx;

	hash = MAGIC_NUMBER;
	idx = -1;
	while (key && key[++idx])
	{
		hash = ((hash << 5) + hash) + key[idx];
		idx++;
	}
	return (hash % size);
}

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
		value = get_value_from_env(env[idx]);
		hash_insert(create_ht_item(key, value), table);
		free(key);
		free(value);
		idx++;
	}
	return (table);
}
