/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:58:16 by mingkim           #+#    #+#             */
/*   Updated: 2022/10/31 10:45:50 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	main(int ac, char **av)
{
	int	len;

	len = 0;
	while (len < ac)
	{
		printf("av[%d] = %s\n", len, av[len]);
		len++;
	}
	len = 0;
	while (environ[len])
	{
		printf("environ[%d] = %s\n", len, environ[len]);
		len++;
	}
	return (0);
}
