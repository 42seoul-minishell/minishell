/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:18:25 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:18:26 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*_get_pwd(void)
{
	char	*buffer;

	buffer = NULL;
	return (getcwd(buffer, 0));
}

static char	*_init_prompt_name(void)
{
	return (ft_strdup("MINISHELL"));
}

static char	*_concat_prompt_name(char *pwd, char *name, char *tail)
{
	char	*full_sentence;
	char	*temp;

	temp = ft_strjoin(pwd, name);
	free(pwd);
	free(name);
	full_sentence = ft_strjoin(temp, tail);
	free(temp);
	free(tail);
	return (full_sentence);
}

char	*create_prompt(void)
{
	char	*pwd;
	char	*name;
	char	*tail;

	pwd = _get_pwd();
	printf("pwd = %s\n", pwd);
	name = _init_prompt_name();
	tail = ft_strdup("$ ");
	return (_concat_prompt_name(name, ft_strdup(" "), tail));
}
