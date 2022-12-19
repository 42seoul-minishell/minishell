/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:28:28 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:28:29 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	**dp_malloc(size_t size)
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

void	free_dp(void **dp)
{
	int	i;

	i = 0;
	while (dp[i])
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}
