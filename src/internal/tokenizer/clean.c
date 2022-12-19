/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:26:45 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:26:46 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void _space_around_operator(char *dest, char *src, size_t len)
{
	size_t dest_idx;
	size_t src_idx;

	dest_idx = 0;
	src_idx = 0;
	while (dest_idx < len && src[src_idx])
	{
		if (is_operator(src + src_idx))
		{
			if (is_double_operator(src + src_idx))
			{
				dest[dest_idx++] = ' ';
				dest[dest_idx++] = src[src_idx++];
				dest[dest_idx++] = ' ';
				continue;
			}
			dest[dest_idx++] = ' ';
			dest[dest_idx++] = src[src_idx++];
			dest[dest_idx++] = src[src_idx++];
			dest[dest_idx++] = ' ';
			continue;
		}
		dest[dest_idx++] = src[src_idx++];
	}
	dest[dest_idx] = '\0';
}

static int _count_operator(char *str)
{
	char *tmp;
	int cnt;

	cnt = 0;
	tmp = str;
	while (*tmp)
	{
		if (is_operator(tmp))
			cnt++;
		tmp++;
	}
	return (cnt);
}

char *make_clean_sentence(char *str)
{
	char *cleaned;
	int len;

	len = ft_strlen(str) + (_count_operator(str) * 2) + 1;
	cleaned = (char *)sp_malloc(sizeof(char) * len);
	_space_around_operator(cleaned, str, len);
	return (cleaned);
}
