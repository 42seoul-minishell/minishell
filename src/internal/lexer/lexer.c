/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:17:33 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/16 17:34:33 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	pass_space(int *index, char *line)
{
	while (line[*index])
	{
		if (line[*index] != ' ')
			break ;
		*index += 1;
	}
}

static void	white_to_space(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\v' || str[i] == '\r')
			str[i] = ' ';
		i++;
	}
}

/* 명령어 순서 확인 */
/* 존재하는 명령어인지 확인 */
/*  */

void	lexer(char *str)
{
	int		i;
	char	*line;

	if ((is_have(str, '"') == TRUE && is_pair_double_quotes(str) == FALSE) \
	|| (is_have(str, '(') == TRUE && is_pair_bracket(str, '(', ')') == FALSE) \
	|| (is_space_around_operator(str) == FALSE))
		exit(1);
	i = 0;
	white_to_space(str);
	line = ft_strtrim(str, " ");
	while (line[i])
	{
		if (ft_strchr("\'\"", line[i]))
			; // add_token(tokens, check_quote(&i, line));
		else if (ft_strchr("()", line[i]))
			; // add_token(tokens, check_parens(&i, line));
		else
			; // add_token(tokens, check_cmd_or_option(&i, line));
		pass_space(&i, line);
		// if (!*tokens)
			// break ;
		if (i > (int)ft_strlen(line))
			break ;
	}
}
