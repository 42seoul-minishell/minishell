/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:06:52 by bolee             #+#    #+#             */
/*   Updated: 2022/03/29 13:02:23 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**free_all(char ***res)
{
	while (**res)
	{
		free(**res);
		(*res)++;
	}
	free(*res);
	*res = 0;
	return (0);
}

static int	cnt_words(char const *s, char c, int include)
{
	int	i;
	int	cnt;

	i = 0;
	if (s[0] == '\0')
		return (0);
	while (!include && s[i] == c)
		i++;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (include)
				cnt++;
			i++;
		}
		else
		{
			while (s[i] && s[i] != c)
				i++;
			cnt++;
		}
	}
	return (cnt);
}

static int	find_len(char const *s, int start, char c)
{
	int	len;

	len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c, int include)
{
	int		i;
	int		start;
	int		words;
	int		sep_off;
	char	**res;

	if (!s)
		return (0);
	words = cnt_words(s, c, include);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (!res)
		return (0);
	res[words] = 0;
	i = -1;
	start = 0;
	while (++i < words)
	{
		while (!include && s[start] == c)
			start++;
		sep_off = find_len(s, start, c);
		if (include && s[start] == c)
			sep_off++;
		res[i] = malloc(sep_off + 1);
		if (!(res[i]))
			return (free_all(&res));
		ft_strlcpy(res[i], (s + start), sep_off + 1);
		start += sep_off;
	}
	return (res);
}
