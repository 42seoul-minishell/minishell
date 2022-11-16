/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:42:46 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/14 15:02:21 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_pointers(size_t length, ...)
{
	va_list	ap;
	void	*next;
	size_t	idx;

	idx = 0;
	va_start(ap, length);
	while (idx < length)
	{
		next = va_arg(ap, void *);
		free(next);
	}
	va_end(ap);
	printf("END");
}
