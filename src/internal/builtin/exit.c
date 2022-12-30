/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:17:51 by bolee             #+#    #+#             */
/*   Updated: 2022/12/28 17:37:33 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
   - input -
   exit hello

   - result -
   exit
   bash: exit: hello: numeric argument required


   - input -
   exit hello world

   - result -
   exit
   bash: exit: hello: numeric argument required
*/
static int  _is_numeric_string(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	builtin_exit(t_list *lst)
{
	int		exit_code;
	char	*value;

	if (!lst)
		exit_code = 0;
	value = ((t_token *) lst->content)->value;
	if (_is_numeric_string(value) == FALSE)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		ft_putstr_fd("MINISHELL: exit: ", STDOUT_FILENO);
		ft_putstr_fd(value, STDOUT_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDOUT_FILENO);
		exit(-1);
	}
	exit_code = ft_atoi(((t_token *) lst->content)->value);
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	exit(exit_code);
}
