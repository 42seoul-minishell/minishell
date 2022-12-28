/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:18:30 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:18:31 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_sig_handler(int signal)
{
	char	*prompt;

	if (signal == SIGINT)
	{
		prompt = create_prompt();
		printf("%s\n", prompt);
		free(prompt);
	}
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

void	set_signal(void)
{
	signal(SIGINT, _sig_handler);
	signal(SIGQUIT, SIG_IGN);
}

static void	_sig_execute(int siganl)
{
	if (siganl == SIGINT)
		ft_putstr_fd("\n", 1);
	else if (siganl == SIGQUIT)
		ft_putstr_fd("Quit: 3\n", 1);
}

void	set_execute_signal(void)
{
	signal(SIGINT, _sig_execute);
	signal(SIGQUIT, _sig_execute);
}
