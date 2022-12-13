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
		exit_error(strerror(errno));
	printf("%s\n", path);
	free(path);
}
