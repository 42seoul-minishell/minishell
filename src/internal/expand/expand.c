/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:53:00 by bolee             #+#    #+#             */
/*   Updated: 2022/11/21 15:08:03 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	get_expand_end_idx(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '$' && str[i] != '\"' \
		&& str[i] != '\'')
		i++;
	return (i);
}

static char	*get_env(const char *str, int idx)
{
	int			end;
	char		*env_key;
	char		*env_value;

	end = get_expand_end_idx(&str[idx + 1]);
	env_key = ft_substr(str, idx + 1, end);
	env_value = search(g_global->envp, env_key);
	if (!env_value)
		return (ft_strdup(""));
	return (ft_strdup(env_value));
}

static void	replace_expand(char **str, int *idx)
{
	char	*tmp;

	if ((*str)[*idx + 1] && (*str)[*idx + 1] == '?')
	{
		tmp = ft_itoa(g_global->status);
		check_single_pointer(tmp);
		if (*idx)
			idx_is_not_zero(str, idx, tmp);
		else
			idx_is_zero(str, idx, tmp);
	}
	else if ((*str)[*idx + 1] && (*str)[*idx + 1] == '$')
		*idx += 1;
	else
	{
		tmp = get_env(*str, *idx);
		check_single_pointer(tmp);
		if (*idx)
			idx_is_not_zero(str, idx, tmp);
		else
			idx_is_zero(str, idx, tmp);
	}
}

void	expand(t_doubly_list *lst)
{
	int				i;
	t_doubly_node	*node;

	node = lst->header.next;
	while (node)
	{
		if (node->token->type >= CMD && node->token->type <= D_QUOTE)
		{
			i = 0;
			while (node->token->value[i])
			{
				if (node->token->value[i] == '$')
					replace_expand(&(node->token->value), &i);
				i++;
			}
		}
		node = node->next;
		if (node == lst->header.next)
			break ;
	}
}
