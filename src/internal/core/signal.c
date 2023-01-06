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


static void	_sig_handler(int sig)
{
	char	*prompt;

	(void) sig;
	if (sig == SIGINT)
	{
		prompt = create_prompt();
		printf("%s\n", prompt);
		free(prompt);
		g_global.status = 1;
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
	signal(SIGCHLD, SIG_IGN);
}

void	sig_child_exit(int sig)
{
	int			pid;
	t_list		*lst;
	t_children	*child;
	int			status;

	(void) sig;
	pid = wait(&status);
	lst = g_global.pipe_status;
	if (!lst)
		g_global.status = check_status(status);
	while (lst)
	{
		child = lst->content;
		if (child->pid == pid)
		{
			child->status = status;
			break ;
		}
		lst = lst->next;
	}
}

static void	_sig_execute(int sig)
{
	t_list *lst;
	t_children *child;

	lst = g_global.pipe_status;
	while (lst)
	{
		child = lst->content;
		if (child->pid > 0)
			kill(child->pid, SIGKILL);
		lst = lst->next;
	}
	if (sig == SIGINT)
		ft_putstr_fd("\n", 1);
	else if (sig == SIGQUIT)
		ft_putstr_fd("Quit: 3\n", 1);
}

void	set_execute_signal(void)
{
	signal(SIGINT, _sig_execute);
	signal(SIGQUIT, _sig_execute);
	signal(SIGCHLD, sig_child_exit);
}
