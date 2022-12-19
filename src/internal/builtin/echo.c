/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:17:33 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:17:34 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_echo(const char *str, int fd, int flag)
{
	char	*newline_str;

	if (!flag)
		return (write(fd, str, ft_strlen(str)) == -1);
	newline_str = ft_strjoin(str, "\n");
	if (!newline_str)
		return (FALSE);
	write(fd, newline_str, ft_strlen(newline_str));
	free(newline_str);
	return (TRUE);
}
