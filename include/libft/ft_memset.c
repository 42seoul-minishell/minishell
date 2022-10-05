/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:01:33 by bolee             #+#    #+#             */
/*   Updated: 2022/03/11 13:47:36 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp_b;
	unsigned char	chr;

	i = 0;
	tmp_b = (unsigned char *) b;
	chr = (unsigned char) c;
	while (i < len)
	{
		tmp_b[i] = chr;
		i++;
	}
	return (b);
}
