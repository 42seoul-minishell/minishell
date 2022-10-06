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

static int	cnt_words(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i] == c)
		i++;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			cnt++;
		i++;
	}
	if (s[i - 1] != c)
		cnt++;
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

static char	*set_str(char const *s, int start, char c)
{
	int		i;
	int		len;
	char	*ptr;

	len = find_len(s, start, c);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	int		words;
	char	**res;

	if (!s)
		return (0);
	words = cnt_words(s, c);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (!res)
		return (0);
	res[words] = 0;
	i = -1;
	start = 0;
	while (++i < words)
	{
		while (s[start] == c)
			start++;
		res[i] = set_str(s, start, c);
		if (!(res[i]))
			return (free_all(&res));
		start += find_len(s, start, c);
	}
	return (res);
}
