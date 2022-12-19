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

#include "minishell.h"

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
	char	*tmp;

	if (ft_strncmp(d_name, prefix, ft_strlen(prefix)) != 0)
		return (NULL);
	tmp = ft_strdup(d_name);
	if (!tmp)
		exit_error("\033[31mError: ft_substr(): Failed to subtract string\n\033[0m");
	return (tmp);
}

static	int	is_have_suffix(char *d_name, char *suffix)
{
	int	d_name_len;
	int	suffix_len;

	d_name_len = ft_strlen(d_name) - 1;
	suffix_len = ft_strlen(suffix) - 1;
	if (d_name_len < suffix_len)
		return (FALSE);
	while (suffix_len >= 0)
	{
		if (d_name[d_name_len] != suffix[suffix_len])
			return (FALSE);
		d_name_len--;
		suffix_len--;
	}
	return (TRUE);
}

char	*only_suffix(char *d_name, char *suffix)
{
	char	*tmp;

	if (is_have_suffix(d_name, suffix) == FALSE)
		return (NULL);
	tmp = ft_strdup(d_name);
	if (!tmp)
		exit_error("\033[31mError: ft_substr(): Failed to subtract string\n\033[0m");
	return (tmp);
}

char	*both_have(char *d_name, t_wildcard *wildcard)
{
	char	*tmp;

	if (ft_strncmp(d_name, wildcard->prefix, ft_strlen(wildcard->prefix)) == 0 && \
			is_have_suffix(d_name, wildcard->suffix) == TRUE)
	{
		tmp = ft_strdup(d_name);
		if (!tmp)
			exit_error("\033[31mError: ft_substr(): Failed to subtract string\n\033[0m");
		return (tmp);
	}
	return (NULL);
}
