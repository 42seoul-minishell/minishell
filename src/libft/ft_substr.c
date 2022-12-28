/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:27:16 by bolee             #+#    #+#             */
/*   Updated: 2022/03/15 12:58:42 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*deal_except(void)
{
	char	*ptr;

	ptr = (char *)ft_malloc(1 * sizeof(char));
	*ptr = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_size;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	s_size = ft_strlen(s);
	if (start > s_size)
	{
		res = deal_except();
		return (res);
	}
	if (len > s_size)
		len = s_size;
	res = (char *)ft_malloc((len + 1) * sizeof(char));
	i = start;
	j = 0;
	while (j < len)
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}
