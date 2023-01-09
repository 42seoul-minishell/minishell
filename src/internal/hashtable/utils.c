/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:25:25 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:25:46 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_key_from_env(char *str)
{
	size_t	idx;
	char	*key;

	idx = 0;
	while (str[idx] != '=')
		idx++;
	key = ft_substr(str, 0, idx);
	return (key);
}

char	*get_value_from_env(char *env)
{
	int		idx;
	int		len_value;
	char	*value;

	idx = 0;
	while (env[idx] != '=')
		idx++;
	len_value = 0;
	while (env[len_value + idx + 1])
		len_value++;
	value = ft_substr(env, idx + 1, len_value);
	return (value);
}

void	prevent_collision(t_hashtable *table, size_t hash, \
							t_ht_item *new)
{
	t_ht_item	*item;

	item = table->items[hash];
	while (item->next)
	{
		if (ft_strncmp(item->key, new->key, ft_strlen(new->key) + 1) == 0)
		{
			free(item->value);
			item->value = ft_strdup(new->value);
			delete_item(new);
			return ;
		}
		item = item->next;
	}
	item->next = new;
	new->next = NULL;
	table->count++;
}

void	display_hashtable(t_hashtable *table, int out_fd)
{
	size_t			idx;
	t_ht_item		*item;

	idx = 0;
	while (idx < table->size)
	{
		item = table->items[idx];
		while (item != NULL)
		{
			ft_putstr_fd(item->key, out_fd);
			ft_putstr_fd("=", out_fd);
			ft_putstr_fd(item->value, out_fd);
			ft_putstr_fd("\n", out_fd);
			item = item->next;
		}
		idx++;
	}
}
