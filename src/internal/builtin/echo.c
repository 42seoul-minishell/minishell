/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:17:33 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:17:34 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_echo_print_quote(char *str, int fd)
{
	int	i;

	if (fd < 0)
		return ;
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

static void	_echo_print(t_list *lst)
{
	t_token	*token;
	char	*value;

	while (lst)
	{
		token = (t_token *) lst->content;
		value = token->value;
		if (token->type == D_QUOTE || token->type == S_QUOTE)
		{
			_echo_print_quote(value, STDOUT_FILENO);
			ft_putstr_fd(" ", STDOUT_FILENO);
		}
		else
		{
			ft_putstr_fd(value, STDOUT_FILENO);
			ft_putstr_fd(" ", STDOUT_FILENO);
		}
		lst = lst->next;
	}
}

// return 0 -> 잘 동작
// return 1 -> 에러 발생
int	builtin_echo(t_list *lst)
{
	int		option;

	if (!lst)
	{
		ft_putstr_fd("\n", STDIN_FILENO);
		return (0);
	}
	option = 0;
	if (ft_strcmp(((t_token *) lst->content)->value, "-n") == 0)
	{
		option = 1;
		lst = lst->next;
	}
	_echo_print(lst);
	if (!option)
		ft_putstr_fd("\n", 1);
	return (0);
}
