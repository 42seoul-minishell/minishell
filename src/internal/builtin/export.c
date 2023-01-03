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

	not a valid identifier -> exit code 1
	첫글자가 대부분의 특수문자 + 숫자 => not a valid indentifier
	#, non => declar -x (env list)
	export # a=b => 출력 후 뒤에 무시
	export a=b # => env 저장 후 # 무시
*/
static void	set_env(char *key, char *value)
{
	t_ht_item		*item;
	char			*tmp;

	tmp = search(g_global.envp, key);
	if (!tmp)
	{
		item = create_ht_item(key, value);
		hash_insert(item, g_global.envp);
	}
	update_value(g_global.envp, key, ft_strdup(value));
}

static int	_is_valid_identifier(char *str, int *exit_code)
{
	if (ft_isalpha(*str) || *str == '_')
		return (TRUE);
	ft_putstr_fd("MINISHELL: export: `", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
	*exit_code = 1;
	return (FALSE);
}

int	builtin_export(t_list *lst, int out_fd)
{
	int		exit_code;
	char	*data;
	char	*key;
	char	*value;

	exit_code = 0;
	if (lst == NULL || ((t_token *) lst->content)->value[0] == '#')
	{
		display_hashtable(g_global.envp, out_fd);
		return (0);
	}
	while (lst)
	{
		data = ((t_token *) lst->content)->value;
		if (_is_valid_identifier(value, &exit_code) == TRUE && \
			ft_strchr(data, '='))
		{
			key = get_key_from_env(data);
			value = get_key_from_env(data);
			set_env(key, value);
		}
		lst = lst->next;
	}
	return (exit_code);
}
