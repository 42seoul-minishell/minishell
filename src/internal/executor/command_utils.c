/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsoh <junsoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:51:18 by junsoh            #+#    #+#             */
/*   Updated: 2023/01/06 19:51:19 by junsoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_cmd(char *abs_path, char *argv[])
{
	if (access(abs_path, X_OK) == -1)
		exit_error("MINISHELL");
	if (execve(abs_path, argv, g_global.envp_arr) == -1)
		exit_error("MINISHELL\n");
}

static void	_set_in_fd(t_bintree_node *node, t_token *file_token, \
							t_token *token, int *in_fd)
{
	if (*in_fd != 0)
		close(*in_fd);
	if (token->type == INP_RDIR)
		*in_fd = open(file_token->value, O_RDONLY);
	else
		*in_fd = node->fd[0];
}

int	set_in(t_bintree_node *node, int in_fd)
{
	t_token	*token;
	t_token	*file_token;
	t_list	*lst;

	lst = node->token_lst;
	while (lst && lst->next)
	{
		token = lst->content;
		if (token->type == INP_RDIR || token->type == HERE_DOC)
		{
			file_token = lst->next->content;
			_set_in_fd(node, file_token, token, &in_fd);
			if (in_fd == -1)
			{
				perror(file_token->value);
				break ;
			}
			lst = lst->next;
		}
		lst = lst->next;
	}
	return (in_fd);
}

static void	_set_out_fd(t_token *token, t_token *file_token, int *out_fd)
{
	if (*out_fd != 1)
		close(*out_fd);
	if (token->type == OUT_RDIR)
		*out_fd = open(file_token->value, O_CREAT | O_WRONLY | \
						O_TRUNC | O_CLOEXEC, 0644);
	else
		*out_fd = open(file_token->value, O_APPEND | O_CREAT | \
						O_WRONLY | O_CLOEXEC, 0644);
}

int	set_out(t_bintree_node *node, int out_fd)
{
	t_token	*token;
	t_token	*file_token;
	t_list	*lst;

	lst = node->token_lst;
	while (lst && lst->next)
	{
		token = lst->content;
		if (token->type == OUT_RDIR || token->type == APP_RDIR)
		{
			file_token = lst->next->content;
			_set_out_fd(token, file_token, &out_fd);
			if (out_fd == -1)
			{
				perror(file_token->value);
				break ;
			}
			lst = lst->next;
		}
		lst = lst->next;
	}
	return (out_fd);
}
