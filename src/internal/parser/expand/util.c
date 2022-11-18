/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:54:18 by bolee             #+#    #+#             */
/*   Updated: 2022/11/18 17:01:59 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minishell.h"

void	idx_is_not_zero(char **str, int *i, char *add)
{
	int		len;
	char	*tmp;
	char	*front;
	char	*back;

	len = ft_strlen(add);
	front = ft_substr(*str, 0, (size_t) i);
	back = ft_substr(*str, *i + len + 1, \
		ft_strlen(*str) - *i - len - 1);
	tmp = ft_strjoin(front, add);
	free(front);
	free(add);
	free(*str);
	check_single_pointer(tmp);
	*str = ft_strjoin(tmp, back);
	free(tmp);
	free(back);
	check_single_pointer(*str);
	if (len != 1)
		*i += len;
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
	check_single_pointer(*str);
	if (len != 1)
		*i += len;
}
