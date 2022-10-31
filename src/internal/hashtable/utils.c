/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:10:28 by gimmingyu         #+#    #+#             */
/*   Updated: 2022/10/31 15:14:58 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

char	*get_key_from_env(char *str)
{
	size_t	idx;
	char	*key;

	idx = 0;
	while (str[idx] != '=')
		idx++;
	key = ft_substr(str, 0, idx);
	return (key);
}

char	*get_value_from_env(char **env)
{
	int		idx;
	int		len_of_env;
	char	*value;

	idx = 0;
	while (env[idx] != '=')
		idx++;
	len_of_env = idx;
	while (env[len_of_env])
		len_of_env++;
	value = ft_substr(env, idx + 1, len_of_env);
	return (value);
}
