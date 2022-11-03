/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:45:12 by bolee             #+#    #+#             */
/*   Updated: 2022/09/21 18:52:10 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	compare_type(t_token *t1, t_token *t2)
{
	if (t1->type >= t2->type)
		return (1);
	return (0);
}

int	is_null(char *str)
{
	if (strcmp("\0", str) == 0)
		return (1);
	return (0);
}

int	is_pipe(char *str)
{
	if (strcmp(str, "|") == 0)
		return (1);
	return (0);
}

int	is_redirect(char *str)
{
	if (strcmp(str, ">>") == 0 || \
			strcmp(str, ">") == 0 || \
			strcmp(str, "<<") == 0 || \
			strcmp(str, "<") == 0)
		return (1);
	return (0);
}

int	is_double_quotes(char *str)
{
	if (ft_strchr(str, '\'') != NULL)
		return (1);
	return (0);
}

int	is_single_quotes(char *str)
{
	if (ft_strchr(str, '"') == 0)
		return (1);
	return (0);
}

t_token	*make_token(char *str)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		exit(1);
	token->str = str;
	if (is_null(str))
		token->type = T_NULL;
	else if (is_pipe(str))
		token->type = T_PIPE;
	else if (is_redirect(str))
		token->type = T_REDIRECT;
	else if (is_double_quotes(str))
		token->type = T_DOUBLE_QUOTES;
	else if (is_single_quotes(str))
		token->type = T_SINGLE_QUOTES;
	else
		token->type = T_WORD;
	return (token);
}
