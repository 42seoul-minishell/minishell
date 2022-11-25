/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:43:14 by bolee             #+#    #+#             */
/*   Updated: 2022/11/23 16:43:17 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h";

t_bintree_node	*get_last_rc_node(t_bintree_node *node)
{
	t_bintree_node	*tmp;

	tmp = node;
	while (tmp)
		tmp = node->rc;
	return (tmp);
}

t_bintree_node	*get_last_lc_node(t_bintree_node *node)
{
	t_bintree_node	*tmp;

	tmp = node;
	while (tmp)
		tmp = node->lc;
	return (tmp);
}
