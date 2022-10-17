/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:12:32 by mingkim           #+#    #+#             */
/*   Updated: 2022/10/17 13:07:09 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

// static void	_invalid_err_cd(const char *str)
// {
// 	printf("cd: No such file or directory: %s\n", str);
// }

int	builtin_cd(char *directory)
{
	if (chdir(directory) == 0)
		return (TRUE);
	return (FALSE);
}
