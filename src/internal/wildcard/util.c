/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:28:03 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:28:03 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_prefix(char *str)
{
	char	*prefix;
	int		start;
	int		len;

	len = 0;
	while (str[len] && str[len] != '*')
		len++;
	if (len == 0)
		return (NULL);
	start = len;
	while (start != 0 && str[start] != ' ')
		start--;
	if (start != 0)
		start++;
	prefix = ft_substr(str, start, len - start);
	if (!prefix)
		exit_error("\033[31mError: ft_substr(): \
			Failed to subtract string\n\033[0m");
	return (prefix);
}

char	*get_suffix(char *str)
{
	char	*suffix;
	int		pos;
	int		len;

	pos = 0;
	len = ft_strlen(str);
	while (str[pos] && str[pos] != '*')
		pos++;
	if (pos == len - 1)
		return (NULL);
	suffix = ft_substr(str, pos + 1, len - pos - 1);
	if (!suffix)
		exit_error("\033[31mError: ft_substr(): \
			Failed to subtract string\n\033[0m");
	return (suffix);
}

char	*join_with_blank(char *str1, char *str2)
{
	int		total_len;
	char	*res;
	char	*tmp;

	total_len = ft_strlen(str1) + ft_strlen(str2) + 2;
	res = (char *)sp_malloc(total_len * sizeof(char));
	tmp = res;
	while (*str1)
		*(tmp++) = *(str1++);
	*(tmp++) = ' ';
	while (*str2)
		*(tmp++) = *(str2++);
	*tmp = '\0';
	return (res);
}

char	*wildcard_join(char **split)
{
	int		i;
	char	*tmp;
	char	*res;

	i = 1;
	res = ft_strdup(split[0]);
	if (!res)
		exit_error("\033[31mError: ft_strdup(): \
			Failed to duplicate string\n\033[0m");
	while (split[i])
	{
		tmp = res;
		res = join_with_blank(tmp, split[i]);
		printf("res: %s\n", res);
		free(tmp);
		i++;
	}
	return (res);
}

DIR	*get_dir_pointer(t_wildcard	*wildcard)
{
	char	*tmp;
	DIR		*dir;

	if (wildcard->prefix && ft_strchr(wildcard->prefix, '/'))
	{
		tmp = ft_substr(wildcard->prefix, 0, \
			ft_strrchr(wildcard->prefix, '/') - wildcard->prefix + 1);
		if (!tmp)
			exit_error("\033[31mError: ft_substr(): \
				Failed to subtract string\n\033[0m");
		dir = opendir(tmp);
		free(tmp);
	}
	else
		dir = opendir(".");
	return (dir);
}
