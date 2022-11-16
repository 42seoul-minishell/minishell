/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:23:00 by bolee             #+#    #+#             */
/*   Updated: 2022/11/16 15:23:01 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bintree.h"

int test_create_bintree(void)
{
	t_bintree *bintree;

	bintree = create_bintree();
	if (bintree == NULL)
		return (FALSE);
	free(bintree);
	return (TRUE);
}

int test_create_bintree_node(void)
{
	t_bintree_node *node;
	t_token token;

	init_token(&token, 0, "TEST");
	node = create_bintree_node(&token);
	if (node == NULL)
		return (FALSE);
	free(node);
	return (TRUE);
}
