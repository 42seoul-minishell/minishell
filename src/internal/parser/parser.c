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

#include "minishell.h"

int	parser(char *str)
{
	t_doubly_list	*lst;

	lst = create_doubly_list();
	tokenizer(lst, str);
	expand(lst);
	relocation_doubly_lst(lst);
	wildcard(lst);
	relocation_doubly_lst(lst);
	// display_list(lst);
	if (syntax(lst) == FALSE)
	{
		release_doubly_list(lst);
		return (FALSE);
	}
	// display_bintree_by_2d(g_global.tree);
	release_doubly_list(lst);
	return (TRUE);
}
