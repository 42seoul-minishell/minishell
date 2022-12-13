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

#include "../../include/minishell.h"

void	display_ctrlx_set(int flag)
{
	if (flag == DISPLAY)
		tcsetattr(STDIN_FILENO, TCSANOW, &(g_global->display_set));
	else if (flag == NODISPLAY)
		tcsetattr(STDOUT_FILENO, TCSANOW, &(g_global->nodisplay_set));
}

void	sig_exec(int sig)
{
	if (sig == SIGINT)
		ft_putstr_fd("\n", STDOUT_FILENO);
	else if (sig == SIGQUIT)
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
}

void	redir_unlink(void)
{
	int		hd_cnt;
	char	*filename;

	hd_cnt = 0;
	while (hd_cnt <= g_global->heredoc_cnt)
	{
		filename = ft_strjoin(".here_doc", ft_itoa(hd_cnt));
		if (access(filename, F_OK) == 0)
			unlink(filename);
		free(filename);
		hd_cnt++;
	}
}

int	check_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (WCOREFLAG | WTERMSIG(status));
}
