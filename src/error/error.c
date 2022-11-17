/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:13:12 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/16 15:45:38 by mingkim          ###   ########.fr       */
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
