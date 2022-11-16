/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:15:34 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/16 15:20:18 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_global	*create_global(t_doubly_list *lst, t_hashtable *envp)
{
	t_global	*global;

	global = malloc(sizeof(t_global));
	if (!global)
		exit(1);
	global->envp = envp;
	global->lst = lst;
	global->status = 0;
	return (global);
}
