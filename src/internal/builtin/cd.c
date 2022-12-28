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

#include "minishell.h"

static int	_cd_home(char *pwd)
{
	char		*oldpwd;
	t_ht_item	*item;

	oldpwd = search(g_global.envp, "OLDPWD");
	if (oldpwd)
		update_value(g_global.envp, "OLDPWD", ft_strdup(pwd));
	else
	{
		item = create_ht_item("OLDPWD", "");
		hash_insert(item, g_global.envp);
	}
	chdir(getenv("HOME"));
	free(path);
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		ft_putstr_fd("\033[31mError: getcwd(): \
			Failed to get current working directory\n\033[0m", STDERR_FILDNO);
		return (1);
	}
	update_value(g_global.envp, "PWD", ft_strdup(pwd));
	free(path);
	return (0);
}

static int	_cd_prev(char *pwd)
{
	char	*oldpwd;

	oldpwd = search(g_global.envp, "OLDPWD");
	if (!oldpwd || ft_strcmp(oldpwd, "") == 0)
	{
		ft_putstr_fd("minsh: cd: OLDPWD not set\n", STDERR_FILENO);
		free(pwd);
		return (1);
	}
	if (chdir(oldpwd) == 0)
	{
		update_value(g_global.envp, "PWD", ft_strdup(oldpwd));
		update_value(g_global.envp, "OLD", ft_strdup(pwd));
		free(pwd);
		return (0);
	}
	free(pwd);
	return (1);
}

static int	_cd_chdir(char *pwd, char *path)
{
	if (chdir(path) == 0)
	{
		update_value(g_global.envp, "PWD", ft_strdup(path));
		update_value(g_global.envp, "OLD", ft_strdup(pwd));
		free(pwd);
		return (0);
	}
	if (errno == ENOTDIR)
	{
		ft_putstr_fd("MINISHELL: cd: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": Not a directory\n", STDERR_FILENO);
	}
	else if (errno == ENOENT) (
		ft_putstr_fd("MINISHELL: cd: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": Not such file or directory\n", STDERR_FILENO);
	)
	free(pwd);
	return (1);
}

// return 0 -> 잘 동작
// return 1 -> 에러 발생
int	builtin_cd(t_list *lst)
{
	char	*path;
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		ft_putstr_fd("\033[31mError: getcwd(): \
			Failed to get current working directory\n\033[0m", STDERR_FILENO);
		return (1);
	}
	if (!lst)
		return (_cd_home(pwd));
	path = ((t_token *)lst->content)->value;
	if (ft_strcmp(path, "~") == 0)
		return (_cd_home(pwd));
	else if (ft_strcmp(path, "-") == 0)
		return (_cd_prev(pwd));
	else
		return (_cd_chdir(pwd, path));
}
