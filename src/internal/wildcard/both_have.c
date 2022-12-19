/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_have.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:46:55 by bolee             #+#    #+#             */
/*   Updated: 2022/12/16 15:46:55 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char	*_have_dir(char *d_name, char *prefix, char *suffix)
{
	char	*tmp;
	char	*dir;
	char	*no_dir;

	dir = ft_substr(prefix, 0, ft_strrchr(prefix, '/') - prefix + 1);
	if (!dir)
		exit_error("\033[31mError: ft_substr(): \
						Failed to substract string\n\033[0m");
	no_dir = ft_substr(prefix, ft_strrchr(prefix, '/') - prefix + 1, \
						ft_strlen(ft_strrchr(prefix, '/') + 1));
	if (!no_dir)
		exit_error("\033[31mError: ft_substr(): \
						Failed to substract string\n\033[0m");
	if (ft_strncmp(d_name, no_dir, ft_strlen(no_dir)) == 0 && \
		is_have_suffix(d_name, suffix) == TRUE)
	{
		tmp = ft_strjoin(dir, d_name);
		if (!tmp)
			exit_error("\033[31mError: ft_strjoin(): \
				Failed to join string\n\033[0m");
		free(dir);
		free(no_dir);
		return (tmp);
	}
	free(dir);
	free(no_dir);
	return (NULL);
}

static char	*_no_have_dir(char *d_name, char *prefix, char *suffix)
{
	char	*tmp;

	if (ft_strncmp(d_name, prefix, ft_strlen(prefix)) == 0 && \
		is_have_suffix(d_name, suffix) == TRUE)
	{
		tmp = ft_strdup(d_name);
		if (!tmp)
			exit_error("\033[31mError: ft_substr(): \
				Failed to subtract string\n\033[0m");
		return (tmp);
	}
	return (NULL);
}

char	*both_have(char *d_name, t_wildcard *wildcard)
{
	if (ft_strrchr(wildcard->prefix, '/'))
		return (_have_dir(d_name, wildcard->prefix, wildcard->suffix));
	return (_no_have_dir(d_name, wildcard->prefix, wildcard->suffix));
}
