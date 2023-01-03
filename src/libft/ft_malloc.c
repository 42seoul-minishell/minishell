/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:45:05 by bolee             #+#    #+#             */
/*   Updated: 2022/12/28 13:45:05 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size)
{
	void	*tmp;

	tmp = (void *)malloc(size);
	if (!tmp)
	{
		ft_putstr_fd(\
			"\033[31mError: malloc(): Failed to allocate memory\n\033[0m", 2);
		exit(1);
	}
	return (tmp);
}
