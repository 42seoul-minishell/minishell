/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:13:12 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/18 16:52:53 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	check_single_pointer(void *pointer)
{
	if (pointer == NULL)
		exit(1);
	return ;
}

void	check_double_pointer(void **pointer)
{
	if (pointer == NULL)
		exit(1);
	return ;
}

void	exit_on_error(const char *str)
{
	printf("%s", str);
	exit(1);
}

void	print_error(char *format, ...)
{
	va_list	args;
	char	*arg;

	va_start(args, format);
	ft_putstr_fd("minish: ", 2);
	ft_putstr_fd(format, 2);
	arg = va_arg(args, char *);
	while (arg)
	{
		ft_putendl_fd(arg, 2);
		arg = va_arg(args, char *);
	}
	va_end(args);
}
