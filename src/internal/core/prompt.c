/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:14:59 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/02 13:52:46 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char	*get_pwd(void)
{
	char	*buffer;

	buffer = NULL;
	return (getcwd(buffer, 0));
}

static char	*init_prompt_name(void)
{
	return (ft_strdup("MINISHELL : "));
}

static char	*concat_prompt_name(char *pwd, char *name, char *tail)
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

	pwd = get_pwd();
	name = init_prompt_name();
	tail = ft_strdup("$ ");
	return (concat_prompt_name(name, pwd, tail));
}
