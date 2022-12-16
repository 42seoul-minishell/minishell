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

#include "../../include/minishell.h"

void	exit_error(const char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	syntax_error(const char *str)
{
	printf("MINISHELL: syntax error near unexpected token `%s'\n", str);
}

void	not_found_error(const char *str)
{
	printf("MINISHELL: %s: command not found\n", str);
}

void	no_file_direct_error(const char *str1, const char *str2)
{
	printf("%s: %s: No such file or directory\n", str1, str2);
}
