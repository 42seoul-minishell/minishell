/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:32:04 by mingkim           #+#    #+#             */
/*   Updated: 2022/10/18 14:32:57 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*
   - input -
   exit hello

   - result -
   exit
   bash: exit: hello: numeric argument required


   - input -
   exit hello world

   - result -
   exit
   bash: exit: hello: numeric argument required
*/
void	builtin_exit(int signal)
{
	printf("exit\n");
	g_global->status = signal;
	exit(signal);
}
