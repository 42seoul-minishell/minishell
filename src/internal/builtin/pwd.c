/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:36:03 by mingkim           #+#    #+#             */
/*   Updated: 2022/10/18 12:39:36 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	builtin_pwd(void)
{
	char *path;

	path = getcwd(NULL, 0);
	if (!path)
		return (FALSE);
	printf("%s\n", path);
	free(path);
	return (TRUE);
}
