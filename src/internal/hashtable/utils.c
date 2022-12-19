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
	int		len_of_env;
	char	*value;

	idx = 0;
	while (env[idx] != '=')
		idx++;
	len_of_env = idx;
	while (env[len_of_env])
		len_of_env++;
	value = ft_substr(env, idx + 1, len_of_env);
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

void	display_hashtable(t_hashtable *table)
{
	size_t			idx;
	t_ht_item		*item;
	t_ht_item		*next;

	idx = 0;
	while (idx < table->size)
	{
		item = table->items[idx];
		while (item != NULL)
		{
			next = item->next;
			ft_putendl_fd("----------------------------", 1);
			ft_putstr_fd("| ", 1);
			ft_putstr_fd(item->key, 1);
			ft_putstr_fd(" | = | ", 1);
			ft_putstr_fd(item->value, 1);
			ft_putendl_fd(" |", 1);
			item = next;
		}
		idx++;
	}
	ft_putendl_fd("----------------------------", 1);
}
