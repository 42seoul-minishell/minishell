/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:27:57 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:27:58 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*nothing_have(char *d_name)
{
	char	*tmp;

	tmp = ft_strdup(d_name);
	if (!tmp)
		exit_error("\033[31mError: ft_substr(): Failed to subtract string\n\033[0m");
	return (tmp);
}

char	*only_prefix(char *d_name, char *prefix)
{
	char	*res;
	char	*tmp;

	tmp = ft_strdup(d_name);
	if (!tmp)
		exit_error("\033[31mError: ft_substr(): Failed to subtract string\n\033[0m");
	res = ft_strjoin(prefix, tmp);
	free(tmp);
	if (!res)
		exit_error("\033[31mError: ft_strjoin(): Failed to join strings\n\033[0m");
	return (res);
}

char	*only_suffix(char *d_name, char *suffix)
{
	char	*res;
	char	*tmp;

	tmp = ft_strdup(d_name);
	if (!tmp)
		exit_error("\033[31mError: ft_substr(): Failed to subtract string\n\033[0m");
	res = ft_strjoin(tmp, suffix);
	free(tmp);
	if (!res)
		exit_error("\033[31mError: ft_strjoin(): Failed to join strings\n\033[0m");
	return (res);
}

char	*both_have(char *d_name, t_wildcard *wildcard)
{
	char	*res;
	char	*tmp;

	tmp = ft_strdup(d_name);
	if (!tmp)
		exit_error("\033[31mError: ft_substr(): Failed to subtract string\n\033[0m");
	res = ft_strjoin(wildcard->prefix, tmp);
	free(tmp);
	if (!res)
		exit_error("\033[31mError: ft_substr(): Failed to subtract string\n\033[0m");
	tmp = res;
	res = ft_strjoin(tmp, wildcard->suffix);
	free(tmp);
	if (!res)
		exit_error("\033[31mError: ft_strjoin(): Failed to join strings\n\033[0m");
	return (res);
}
