/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:12:32 by mingkim           #+#    #+#             */
/*   Updated: 2022/10/18 12:24:17 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	_invalid_err_cd(const char *str)
{
	printf("minishell: cd: %s: No such file or directory\n", str);
}

int	builtin_cd(char *directory)
{
	if (chdir(directory) == 0)
		return (TRUE);
	return (FALSE);
}
