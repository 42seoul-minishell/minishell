/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:24:57 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/21 20:36:54 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	executor(char *cmd)
{
	display_bintree_by_preorder(g_global->tree);
	return (run_execute(cmd));
}

int	run_execute(char *cmd)
{
	int	status;

	status = serve_status(cmd);
	return (status);
}

int	serve_status(char *cmd)
{
	int	status;

	printf("cmd = %s\n", cmd);
	status = EXIT_SUCCESS;
	return (status);
}
