/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:09:37 by mingkim           #+#    #+#             */
/*   Updated: 2022/10/18 14:31:04 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

// static int	_insert_env_node(t_doubly_list *lst, t_doubly_node *node)
// {
// 	return (insert_node(lst, node));
// }

// static void	_update_value(t_doubly_node *node, char *value)
// {
// 	free(node->token->value);
// 	node->token->value = value;
// }

// int	builtin_export(t_doubly_list *lst, char *key, char *value)
// {
// 	char			*temp;
// 	char			*full_string;
// 	t_doubly_node	*node;

// 	temp = ft_strjoin(key, "=");
// 	full_string = ft_strjoin(temp, value);
// 	free(temp);
// 	node = find_doubly_node(lst, full_string);
// 	if (!node)
// 		_insert_env_node(lst, node);
// 	else
// 		_update_value(node, full_string);
// 	return (TRUE);
// }

int	builtin_export(char *key, char *value)
{
	size_t			idx;
	t_ht_item 	*item;
	char 		*tmp;

	tmp = search(g_global->envp, key);
	if (!tmp)
	{
		item = create_ht_item(key, value);
		if (!item)
			return (FALSE);
		hash_insert(item, g_global->envp);
		return (TRUE);
	}
	idx = hash_index(key, g_global->envp->size);
	item = g_global->envp->items[idx];
	while (item)
	{
		if (ft_strncmp(item->key, key, ft_strlen(key) + 1) == 0)
		{
			item->value = value;
			break ;
		}
		item = item->next;
	}
	return (TRUE);
}
