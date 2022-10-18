/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:01:16 by mingkim           #+#    #+#             */
/*   Updated: 2022/10/18 12:50:53 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

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
