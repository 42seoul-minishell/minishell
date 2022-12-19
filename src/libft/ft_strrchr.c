/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:54:42 by bolee             #+#    #+#             */
/*   Updated: 2022/03/15 12:55:10 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*u_s;
	unsigned char	u_c;

	u_s = (unsigned char *) s;
	u_c = (unsigned char) c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (u_s[i] == u_c)
			return ((char *) s + i);
		i--;
	}
	return (0);
}
