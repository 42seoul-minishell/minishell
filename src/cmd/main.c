/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:58:16 by mingkim           #+#    #+#             */
/*   Updated: 2022/10/05 12:45:25 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	main(int ac, char **av, char **env)
{
	int	len;
	int	len2;

	len = 0;
	while (len < ac)
	{
		printf("av[%d] = %s\n", len, av[len]);
		len++;
	}
	len2 = 0;
	while (env[len2])
		len2++;
	len = 0;
	return (0);
}
