/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:28:50 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:28:51 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_ctrlx_set(int flag)
{
	int	return_val;

	return_val = 0;
	if (flag == DISPLAY)
		return_val = tcsetattr(STDIN_FILENO, TCSANOW, &(g_global.display_set));
	else if (flag == NODISPLAY)
		return_val = tcsetattr(STDIN_FILENO, TCSANOW, \
			&(g_global.nodisplay_set));
	if (return_val == ERROR)
		exit_error("Error: tcsetattr()");
}

void	sig_exec(int sig)
{
	if (sig == SIGINT)
		ft_putstr_fd("\n", STDOUT_FILENO);
	else if (sig == SIGQUIT)
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
}

void	free_dp(void **dp)
{
	int	i;

	i = 0;
	while (dp[i])
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}
