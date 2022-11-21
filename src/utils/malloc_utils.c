/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 00:46:59 by gimmingyu         #+#    #+#             */
/*   Updated: 2022/11/20 00:47:14 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*sp_malloc(size_t size)
{
	void	*tmp;

	tmp = (void *)malloc(size);
	if (!tmp)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(1);
	}
	return (tmp);
}

void	*dp_malloc(size_t size)
{
	void	**tmp;

	tmp = (void **)malloc(size);
	if (!tmp)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(1);
	}
	return (tmp);
}
