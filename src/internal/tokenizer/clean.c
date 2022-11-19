/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:37:40 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/19 14:09:29 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	space_around_operator(char *dest, char *src, size_t len)
{
	size_t	dest_idx;
	size_t	src_idx;

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
				continue ;
			}
			dest[dest_idx++] = ' ';
			dest[dest_idx++] = src[src_idx++];
			dest[dest_idx++] = src[src_idx++];
			dest[dest_idx++] = ' ';
			continue ;
		}
		dest[dest_idx++] = src[src_idx++];
	}
	dest[dest_idx] = '\0';
}

static int	count_operator(char *str)
{
	char	*tmp;
	int		cnt;

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

char	*make_clean_sentence(char *str)
{
	char	*cleaned;
	int		len;

	len = ft_strlen(str) + (count_operator(str) * 2) + 1;
	cleaned = (char *)malloc(sizeof(char) * len);
	if (!cleaned)
		exit(1);
	space_around_operator(cleaned, str, len);
	return (cleaned);
}
