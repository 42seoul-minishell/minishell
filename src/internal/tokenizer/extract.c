/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:36:52 by bolee             #+#    #+#             */
/*   Updated: 2022/11/19 00:38:03 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*extract_double_quotes(char **str)
{
	char	*start;
	char	*end;
	char	*result;
	char	*tmp;

	if (!str)
		exit(1);
	start = ft_strchr(*str, '"') + 1;
	end = ft_strchr(start, '"') - 1;
	result = ft_substr(*str, start - *str, end - start + 1);
	start = ft_substr(*str, 0, start - *str - 1);
	end = ft_substr(*str, (end - *str) + 2, ft_strlen(*str) - (end - *str) + 1);
	tmp = ft_strjoin(start, end);
	free(*str);
	*str = tmp;
	return (result);
}

char	*extract_brackets(char **str, char open, char close)
{
	char	*start;
	char	*end;
	char	*result;
	char	*tmp;

	if (!str)
		exit(1);
	start = ft_strchr(*str, open) + 1;
	end = ft_strchr(start, close) - 1;
	result = ft_substr(*str, start - *str, end - start + 1);
	start = ft_substr(*str, 0, start - *str - 1);
	end = ft_substr(*str, (end - *str) + 2, ft_strlen(*str) - (end - *str) + 1);
	tmp = ft_strjoin(start, end);
	free(*str);
	*str = tmp;
	return (result);
}
