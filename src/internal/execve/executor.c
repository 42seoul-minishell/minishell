/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:24:57 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/17 20:45:44 by mingkim          ###   ########.fr       */
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

	status = EXIT_SUCCESS;
	return (TRUE);
}
