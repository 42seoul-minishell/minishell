/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:17:59 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:18:02 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	tmp = search(g_global.envp, key);
	if (!tmp)
	{
		item = create_ht_item(key, value);
		if (!item)
			return (FALSE);
		hash_insert(item, g_global.envp);
		return (TRUE);
	}
	update_value(g_global.envp, key, ft_strdup(value));
	return (TRUE);
}
