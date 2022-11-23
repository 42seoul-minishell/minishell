/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:04:17 by bolee             #+#    #+#             */
/*   Updated: 2022/11/23 17:04:18 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	create_tmp_file(void)
{
	int	fd;

	fd = open(TMP_FILE, O_RDONLY | O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		exit_on_error(strerror(errno));
	return (fd);
}

static void	input_tmp_file(int tmp_fd, char *eof)
{
	char	*input;

	signal(SIGINT, interrupt_heredoc);
	while (true)
	{
		input = readline("> ");
		if (!input)
		{
			ft_putstr_fd("minishell: warning: \
				here-document delimited by end-of-file", 1);
			close(tmp_fd);
			exit(0);
		}
		if (ft_strcmp(input, eof))
			ft_putendl_fd(input, tmp_fd);
		else
		{
			close(tmp_fd);
			free(input);
			break ;
		}
		free(input);
	}
	exit(0);
}

static void	make_tmp_file_input(void)
{
	int		tmp_fd;

	tmp_fd = open(TMP_FILE, O_RDONLY);
	dup2(tmp_fd, IN);
	close(tmp_fd);
}

void	heredoc_redirect(t_bintree_node *node)
{
	int	fd[2];
	int	tmp_fd;
	int	pid;
	int	status;

	tmp_fd = create_tmp_file();
	dup2(tmp_fd, STDOUT_FILENO);
	pid = fork();
	if (pid < 0)
		exit_on_error(strerror(errno));
	if (pid == 0)
		input_tmp_file(tmp_fd, node->rc->token->value);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
	{
		close(tmp_fd);
		g_global->status = 130;
	}
	make_tmp_file_input();
	dup2(save_fd_out, STDOUT_FILENO);
	close(save_fd_out);
}
