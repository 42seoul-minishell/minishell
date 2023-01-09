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
		&& str[i] != '\'' && str[i] != ' ')
		i++;
	return (i);
}

static int	_get_key_length(const char *str, int idx)
{
	int		end;
	char	*env_key;
	int		res;

	end = _get_expand_end_idx(&str[idx + 1]);
	env_key = ft_substr(str, idx + 1, end);
	res = ft_strlen(env_key);
	free(env_key);
	return (res);
}

void	idx_is_not_zero(char **str, int *i, char *add)
{
	int		len;
	char	*tmp;
	char	*tmp2;
	char	*front;
	char	*back;

	len = _get_key_length(*str, *i);
	if ((*str)[*i + 1] == '?')
		len = 1;
	front = ft_substr(*str, 0, *i);
	back = ft_substr(*str, *i + len + 1, strlen(*str));
	tmp = ft_strjoin(front, add);
	tmp2 = ft_strjoin(tmp, back);
	free(*str);
	*str = ft_strtrim(tmp2, " ");
	free(add);
	free(tmp);
	free(tmp2);
	free(front);
	free(back);
}

void	idx_is_zero(char **str, int *i, char *add)
{
	int		len;
	char	*tmp;
	char	*back;

	len = _get_key_length(*str, *i);
	if ((*str)[*i + 1] == '?')
		len = 1;
	back = ft_substr(*str, *i + len + 1, \
			ft_strlen(*str) - *i - len - 1);
	free(*str);
	tmp = ft_strjoin(add, back);
	*str = ft_strtrim(tmp, " ");
	free(tmp);
	free(back);
	free(add);
	if (len != 1)
		*i += len;
}
