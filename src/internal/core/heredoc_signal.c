/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsoh <junsoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:43:50 by junsoh            #+#    #+#             */
/*   Updated: 2023/01/06 18:43:52 by junsoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_sig_heredoc(int sig)
{
	(void) sig;
	ft_putstr_fd("\n", 1);
}

void	set_heredoc_signal(void)
{
	signal(SIGINT, _sig_heredoc);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGCHLD, sig_child_exit);
}

static void	_sig_fork_exit(int sig)
{
	(void) sig;
	exit(1);
}

void	set_fork_signal(void)
{
	signal(SIGINT, _sig_fork_exit);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGCHLD, SIG_IGN);
}
