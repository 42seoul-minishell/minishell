/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:17:51 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:17:53 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	g_global.status = signal;
	exit(signal);
}
