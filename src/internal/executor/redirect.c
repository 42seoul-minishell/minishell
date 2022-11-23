/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:07:03 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/16 19:07:14 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	input_redirect(t_bintree_node *node)
{
	int				fd;
	t_bintree_node	*last_rc;

	last_rc = get_last_rc_node(node);
	fd = open(last_rc->token->value, O_RDONLY);
	if (fd < 0)
		exit_on_error(strerror(errno));
	dup2(fd, STDIN_FILENO);
	close(fd);
}

static void	ouput_redirect(t_bintree_node *node)
{
	int	fd;

	fd = open(node->rc->token->value, \
		O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		exit_on_error(strerror(errno));
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

static void	append_redirect(t_bintree_node *node)
{
	int	fd;

	fd = open(node->rc->token->value, \
		O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
		exit_on_error(strerror(errno));
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	execute_redirect(t_bintree_node *node)
{
	if (node->token->type == INP_RDIR)
		input_redirect(node);
	else if (node->token->type == OUT_RDIR)
		ouput_redirect(node);
	else if (node->token->type == APP_RDIR)
		append_redirect(node);
	else if (node->token->type == HERE_DOC)
		heredoc_redirect(node);
}
