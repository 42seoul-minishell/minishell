/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:20:08 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:20:09 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	_input_redirect(t_bintree_node *node)
{
	int				fd;
	t_bintree_node	*last_rc;

	last_rc = get_last_rc_node(node);
	fd = open(last_rc->token->value, O_RDONLY);
	if (fd < 0)
		exit_error(strerror(errno));
	dup2(fd, STDIN_FILENO);
	close(fd);
}

static void	_ouput_redirect(t_bintree_node *node)
{
	int	fd;

	fd = open(node->rc->token->value, \
		O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		exit_error(strerror(errno));
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

static void _append_redirect(t_bintree_node *node)
{
	int fd;

	fd = open(node->rc->token->value, \
		O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
		exit_error(strerror(errno));
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	execute_redirect(t_bintree_node *node)
{
	if (node->token->type == INP_RDIR)
		_input_redirect(node);
	else if (node->token->type == OUT_RDIR)
		_ouput_redirect(node);
	else if (node->token->type == APP_RDIR)
		_append_redirect(node);
	else if (node->token->type == HERE_DOC)
		heredoc_redirect(node);
}
