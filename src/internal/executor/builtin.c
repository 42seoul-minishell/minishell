/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:53:01 by bolee             #+#    #+#             */
/*   Updated: 2022/12/28 14:53:02 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_builtin(t_list *lst)
{
	t_token	*token;
	char	*cmd;

	token = (t_token *)lst->content;
	cmd = token->value;
	if (ft_strcmp(cmd, "echo") == 0 || \
		ft_strcmp(cmd, "cd") == 0 || \
		ft_strcmp(cmd, "pwd") == 0 || \
		ft_strcmp(cmd, "export") == 0 || \
		ft_strcmp(cmd, "unset") == 0 || \
		ft_strcmp(cmd, "env") == 0 || \
		ft_strcmp(cmd, "exit") == 0)
		return (TRUE);
	return (FALSE);
}

int	execute_builtin(t_list *lst, int out_fd)
{
	t_token	*token;
	char	*cmd;

	token = (t_token *)lst->content;
	cmd = token->value;
	if (ft_strcmp(cmd, "echo") == 0)
		return (builtin_echo(lst->next, out_fd));
	else if (ft_strcmp(cmd, "cd") == 0)
		return (builtin_cd(lst->next, out_fd));
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (builtin_pwd(out_fd));
	else if (ft_strcmp(cmd, "export") == 0)
		return (builtin_export(lst->next, out_fd));
	else if (ft_strcmp(cmd, "unset") == 0)
		builtin_unset(lst->next);
	else if (ft_strcmp(cmd, "env") == 0)
		builtin_env(out_fd);
	else if (ft_strcmp(cmd, "exit") == 0)
		builtin_exit(lst->next);
	return (0);
}
