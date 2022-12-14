/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:20:24 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:20:25 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_get_expand_end_idx(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '$' && str[i] != '\"' \
		&& str[i] != '\'' && str[i] != ' ')
		i++;
	return (i);
}

static char	*_get_env(const char *str, int idx)
{
	int		end;
	char	*env_key;
	char	*env_value;

	end = _get_expand_end_idx(&str[idx + 1]);
	env_key = ft_substr(str, idx + 1, end);
	env_value = search(g_global.envp, env_key);
	free(env_key);
	if (!env_value)
		return (ft_strdup(""));
	return (ft_strdup(env_value));
}

static void	_replace_expand(char **str, int *idx)
{
	char	*tmp;

	if ((*str)[*idx + 1] && (*str)[*idx + 1] == '?')
	{
		tmp = ft_itoa(g_global.status);
		if (*idx)
			idx_is_not_zero(str, idx, tmp);
		else
			idx_is_zero(str, idx, tmp);
	}
	else if ((*str)[*idx + 1] && (*str)[*idx + 1] == '$')
		*idx += 1;
	else
	{
		tmp = _get_env(*str, *idx);
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
	char			*tmp;

	node = lst->header.next;
	while (node)
	{
		if (node->token->type == S_QUOTE || node->token->type == D_QUOTE)
		{
			tmp = ft_strtrim(node->token->value, "\'\"");
			free(node->token->value);
			node->token->value = tmp;
		}
		if (node->token->type >= CMD \
			&& node->token->type <= D_QUOTE)
		{
			i = -1;
			while (node->token->value[++i])
				if (node->token->value[i] == '$')
					_replace_expand(&(node->token->value), &i);
		}
		node = node->next;
		if (node == lst->header.next)
			break ;
	}
}
