/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:36:52 by bolee             #+#    #+#             */
/*   Updated: 2022/11/04 16:36:53 by bolee            ###   ########.fr       */
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
		return (NULL);
	start = ft_strchr(*str, '"') + 1;
	end = ft_strchr(start, '"') - 1;
	result = ft_substr(*str, start - *str, end - start + 1);
	if (!result)
		return (NULL);
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
		return (NULL);
	start = ft_strchr(*str, open) + 1;
	end = ft_strchr(start, close) - 1;
	result = ft_substr(*str, start - *str, end - start + 1);
	if (!result)
		return (NULL);
	start = ft_substr(*str, 0, start - *str - 1);
	end = ft_substr(*str, (end - *str) + 2, ft_strlen(*str) - (end - *str) + 1);
	tmp = ft_strjoin(start, end);
	free(*str);
	*str = tmp;
	return (result);
}

char	*extract_pipe(char **str)
{
	return (NULL);
}