/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:09:18 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/17 21:34:33 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minishell.h"

void	make_token_list(t_doubly_list *lst, char *splited)
{
	ssize_t			idx;
	t_tType			type;
	t_token			*token;

	idx = -1;
	while (splited[++idx])
	{
		safe_insert(lst, verify_token(splited + idx), splited);
	}
	free(splited);
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

void	tokenizer(t_doubly_list *lst, char *str)
{
	char	*tmp;

	if (str[0] == '\0')
		return ;
	white_to_space(str);
	tmp = make_clean_sentence(str);
	check_single_pointer((void *) tmp);
	make_token_list(lst, tmp);
	free(tmp);
}
