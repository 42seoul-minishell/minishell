/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:20:29 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:20:30 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_get_expand_end_idx(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '$' && str[i] != '\"' \
			&& str[i] != '\'')
		i++;
	return (i);
}

static int	_get_key_length(const char *str, int idx)
{
	int		end;
	char	*env_key;

	end = _get_expand_end_idx(&str[idx + 1]);
	env_key = ft_substr(str, idx + 1, end);
	return (ft_strlen(env_key));
}

void	idx_is_not_zero(char **str, int *i, char *add)
{
	char	*tmp;
	char	*front;
	char	*back;

	front = ft_substr(*str, 0, *i);
	back = ft_substr(*str, *i + _get_key_length(*str, *i) + 1, ft_strlen(*str));
	tmp = ft_strjoin(front, add);
	free(front);
	free(add);
	free(*str);
	if (!tmp)
		exit_error("\033[31mError: ft_strjoin(): Failed to join strings\n\033[0m");
	*str = ft_strjoin(tmp, back);
	free(tmp);
	free(back);
	if (!*str)
		exit_error("\033[31mError: ft_strjoin(): Failed to join strings\n\033[0m");
}

void	idx_is_zero(char **str, int *i, char *add)
{
	int		len;
	char	*back;

	len = ft_strlen(add);
	back = ft_substr(*str, *i + len + 1, \
			ft_strlen(*str) - *i - len - 1);
	free(*str);
	*str = ft_strjoin(add, back);
	free(back);
	free(add);
	if (!*str)
		exit_error("\033[31mError: ft_strjoin(): Failed to join strings\n\033[0m");
	if (len != 1)
		*i += len;
}
