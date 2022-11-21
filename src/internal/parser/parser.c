/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:15:27 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/21 13:05:05 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	parser(char *str)
{
	t_doubly_list	*lst;

	lst = create_doubly_list();
	tokenizer(lst, str);
	expand(lst);
	display_list(lst);
	// wildcard(lst);
	syntax(lst);
	release_doubly_list(lst);
}
