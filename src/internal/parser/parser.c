/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:26:02 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:26:03 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	parser(char *str)
{
	t_doubly_list	*lst;

	lst = create_doubly_list();
	tokenizer(lst, str);
	// display_list(lst);
	expand(lst);
	display_list(lst);
	// wildcard 수정 필요
	wildcard(lst);
	display_list(lst);
	syntax(lst);
	release_doubly_list(lst);
}
