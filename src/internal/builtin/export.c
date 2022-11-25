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

/* 
	- input -
	export h = 1

	- result -
	h에 대한 value가 없어 정상 작동 되지 않음
	+
	bash: export: `=': not a valid identifier
	bash: export: `1': not a valid identifier


	- input -
	export a=1 b=2
	
	- result -
	둘 다 정상적으로 저장됨
*/
int	builtin_export(char *key, char *value)
{
	size_t			idx;
	t_ht_item		*item;
	char			*tmp;

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
