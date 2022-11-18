/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:24:57 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/18 17:57:08 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	executor(char *cmd)
{
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
	return (TRUE);
}
