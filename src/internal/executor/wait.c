/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsoh <junsoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:49:38 by junsoh            #+#    #+#             */
/*   Updated: 2023/01/05 18:49:39 by junsoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_child(void)
{
	while (waitpid(0, NULL, 0) != -1)
		;
}

int	get_pipe_status(void)
{
	t_list		*lst;
	t_children	*child;

	lst = g_global.pipe_status;
	child = (t_children *)ft_lstlast(g_global.pipe_status)->content;
	return (child->status >> 8 & 0x000000ff);
}
