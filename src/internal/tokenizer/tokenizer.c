/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:09:18 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/19 14:11:15 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	make_token_list(t_doubly_list *lst, char *str)
{	
	char	*content;
	ssize_t	current;
	ssize_t	before;
	ssize_t	len;
	t_tType	token_type;

	current = -1;
	before = 0;
	len = ft_strlen(str);
	while (str[++current] && current < len)
	{
		while (is_operator(str + current) == FALSE && \
				is_quote(str + current) == FALSE)
			current++;
		content = safe_malloc(current - before + 1);
		ft_strlcpy(content, str + before, current - before + 1);
		before = current;
		printf("content = %s\n", content);
		token_type = NONE;
		safe_insert(lst, token_type, content);
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
