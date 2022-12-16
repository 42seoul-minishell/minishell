/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_suffix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:46:51 by bolee             #+#    #+#             */
/*   Updated: 2022/12/16 15:46:52 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*only_suffix(char *d_name, char *suffix)
{
	char	*tmp;

	if (is_have_suffix(d_name, suffix) == FALSE)
		return (NULL);
	tmp = ft_strdup(d_name);
	if (!tmp)
		exit_error("\033[31mError: ft_substr(): \
			Failed to subtract string\n\033[0m");
	return (tmp);
}
