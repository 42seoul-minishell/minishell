/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:54:18 by bolee             #+#    #+#             */
/*   Updated: 2022/11/21 20:34:15 by gimmingyu        ###   ########.fr       */
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

static int	get_key_length(const char *str, int idx)
{
	int			end;
	char		*env_key;

	end = get_expand_end_idx(&str[idx + 1]);
	env_key = ft_substr(str, idx + 1, end);
	return (ft_strlen(env_key));
}

void	idx_is_not_zero(char **str, int *i, char *add)
{
	char	*tmp;
	char	*front;
	char	*back;

	front = ft_substr(*str, 0, *i);
	back = ft_substr(*str, *i + get_key_length(*str, *i) + 1, ft_strlen(*str));
	tmp = ft_strjoin(front, add);
	free(front);
	free(add);
	free(*str);
	if (!tmp)
		exit_on_error("Error...\n");
	*str = ft_strjoin(tmp, back);
	free(tmp);
	free(back);
	if (!*str)
		exit_on_error("Error...\n");
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
		exit_on_error("Error...\n");
	if (len != 1)
		*i += len;
}
