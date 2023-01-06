/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:36:15 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:16:18 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_error(const char *str)
{
	perror(str);
	exit(errno);
}

void	syntax_error(const char *str, int flag)
{
	char	chr[2];
	char	*err_msg;
	char	*tmp;

	if (flag)
	{
		chr[0] = *str;
		chr[1] = '\0';
		tmp = ft_strjoin(\
			"MINISHELL: syntax error near unexpected token `", chr);
	}
	else
		tmp = ft_strjoin(\
			"MINISHELL: syntax error near unexpected token `", str);
	err_msg = ft_strjoin(tmp, "'\n");
	ft_putstr_fd(err_msg, STDERR_FILENO);
	free(tmp);
	free(err_msg);
}

void	not_found_error(const char *str)
{
	char	*err_msg;
	char	*tmp;

	tmp = ft_strjoin("MINISHELL: ", str);
	err_msg = ft_strjoin(tmp, ": command not found\n");
	ft_putstr_fd(err_msg, STDERR_FILENO);
	free(tmp);
	free(err_msg);
}
