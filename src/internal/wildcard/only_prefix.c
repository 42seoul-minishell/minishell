/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_prefix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:38:31 by bolee             #+#    #+#             */
/*   Updated: 2022/12/16 15:38:31 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char	*_have_dir(char *d_name, char *prefix)
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
	if (ft_strncmp(d_name, no_dir, ft_strlen(no_dir)) != 0)
		return (NULL);
	tmp = ft_strjoin(dir, d_name);
	if (!tmp)
		exit_error("\033[31mError: ft_strjoin(): \
						Failed to join string\n\033[0m");
	free(dir);
	free(no_dir);
	return (tmp);
}

static char	*_no_have_dir(char *d_name, char *prefix)
{
	char	*tmp;

	if (ft_strncmp(d_name, prefix, ft_strlen(prefix)) != 0)
		return (NULL);
	tmp = ft_strdup(d_name);
	if (!tmp)
		exit_error("\033[31mError: ft_strdup(): \
					Failed to duplicate string\n\033[0m");
	return (tmp);
}

char	*only_prefix(char *d_name, char *prefix)
{
	if (ft_strrchr(prefix, '/'))
		return (_have_dir(d_name, prefix));
	return (_no_have_dir(d_name, prefix));
}
