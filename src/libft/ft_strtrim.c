/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:41:52 by bolee             #+#    #+#             */
/*   Updated: 2022/03/11 14:01:24 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	find_end(char const *s1, char const *set)
{
	int	i;
	int	s1_size;

	i = 0;
	s1_size = ft_strlen(s1);
	while (i < s1_size)
	{
		if (ft_strchr(set, s1[s1_size - 1 - i]) == 0)
			break ;
		i++;
	}
	return (s1_size - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*res;
	int		i;

	if (!s1 || !set)
		return (0);
	start = find_start(s1, set);
	end = find_end(s1, set);
	if (end < start)
		res = (char *)ft_malloc(1 * sizeof(char));
	else
		res = (char *)ft_malloc((end - start + 1) * sizeof(char));
	i = 0;
	while (start + i < end)
	{
		res[i] = s1[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
