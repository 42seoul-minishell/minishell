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

/*
	- input -
	pwd hello
	pwd 1
	pwd hello word

	- result -
	모두 정상 작동
*/
void	builtin_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
		exit_on_error(strerror(errno));
	printf("%s\n", path);
	free(path);
}
