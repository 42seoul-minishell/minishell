/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:03:39 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:18:09 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(int out_fd)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
	{
		ft_putstr_fd("\033[31mError: getcwd(): \
			Failed to get current working directory\n\033[0m", STDERR_FILENO);
		return (1);
	}
	ft_putstr_fd(path, out_fd);
	ft_putchar_fd('\n', out_fd);
	free(path);
	return (0);
}
