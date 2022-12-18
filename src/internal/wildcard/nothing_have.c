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
		exit_error("\033[31mError: ft_substr(): \
			Failed to subtract string\n\033[0m");
	return (tmp);
}

int	is_have_suffix(char *d_name, char *suffix)
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
