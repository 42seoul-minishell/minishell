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
	char		*prompt;

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

static void	_sig_child_exit(int sig)
{
	int			pid;
	t_list		*lst;
	t_children	*child;
	int			status;

	(void) sig;
	usleep(100);
	pid = wait(&status);
	printf("%d\n", pid);
	lst = g_global.pipe_status;
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
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd(" is finished\n", 1);
}

void	set_signal(void)
{
	signal(SIGINT, _sig_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGCHLD, _sig_child_exit);
}

static void	_sig_execute(int sig)
{
	// int	tmp;
	// t_list *lst;
	// t_children *child;

	// lst = g_global.pipe_status;
	// while (lst)
	// {
	// 	child = lst->content;
	// 	printf("child pid: %i\n", child->pid);
	// 	tmp = kill(child->pid, SIGUSR1);
	// 	usleep(100);
	// 	printf("kill return: %d\n", tmp);
	// 	perror(NULL);
	// 	lst = lst->next;
	// }
	if (sig == SIGINT)
		ft_putstr_fd("\n", 1);
	else if (sig == SIGQUIT)
		ft_putstr_fd("Quit: 3\n", 1);
}

void	set_execute_signal(void)
{
	signal(SIGINT, _sig_execute);
	signal(SIGQUIT, _sig_execute);
}
