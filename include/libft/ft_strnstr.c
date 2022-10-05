/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:52:05 by bolee             #+#    #+#             */
/*   Updated: 2022/03/16 16:33:03 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	if (!(*s2))
		return ((char *) s1);
	i = 0;
	while (s1[i] && i < len)
	{
		j = 0;
		while (s2[j] && i + j < len && s1[i + j] == s2[j])
			j++;
		if (!s2[j])
			return ((char *) s1 + i);
		i++;
	}
	return (0);
}
