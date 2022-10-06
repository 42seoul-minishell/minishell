/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:47:26 by bolee             #+#    #+#             */
/*   Updated: 2022/03/11 12:55:03 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if (!dst && !src)
		return (0);
	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned char *) src;
	if (tmp_dst <= tmp_src)
	{
		while (len--)
			*(tmp_dst++) = *(tmp_src++);
	}
	else
	{
		tmp_dst += (len - 1);
		tmp_src += (len - 1);
		while (len--)
			*(tmp_dst--) = *(tmp_src--);
	}
	return (dst);
}
