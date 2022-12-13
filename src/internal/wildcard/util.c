/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:28:03 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:28:03 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*get_prefix(char *str)
{
	char	*prefix;
	int		len;

	len = 0;
	while (str[len] && str[len] != '*')
		len++;
	if (len == 0)
		return (NULL);
	prefix = ft_substr(str, 0, len);
	if (!prefix)
		exit_error("\033[31mError: ft_substr(): Failed to subtract string\n\033[0m");
	return (prefix);
}

char	*get_suffix(char *str)
{
	char	*suffix;
	int		pos;
	int		len;

	pos = 0;
	len = ft_strlen(str);
	while (str[pos] && str[pos] != '*')
		pos++;
	if (pos == len)
		return (NULL);
	suffix = ft_substr(str, pos + 1, len - pos - 1);
	if (!suffix)
		exit_error("\033[31mError: ft_substr(): Failed to subtract string\n\033[0m");
	return (suffix);
}
