/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:26:10 by bolee             #+#    #+#             */
/*   Updated: 2022/03/11 12:30:36 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	chr;

	i = 0;
	tmp = (unsigned char *) s;
	chr = (unsigned char) c;
	while (i < n)
	{
		if (tmp[i] == chr)
			return ((void *) s + i);
		i++;
	}
	return (0);
}
