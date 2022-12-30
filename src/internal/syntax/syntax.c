/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:26:24 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:26:25 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_is_valid_next_token(t_doubly_node *cur, t_doubly_node *next)
{
	int	cur_type;
	int	next_type;

	cur_type = cur->token->type;
	next_type = next->token->type;
	if ((cur_type == CMD && next_type == BRACKET) \
		|| (cur_type == BRACKET && next_type == CMD) \
		|| (cur_type == BRACKET && next_type == BRACKET))
		return (FALSE);
	if ((cur_type >= INP_RDIR && cur_type <= HERE_DOC) \
		&& !(next_type >= CMD && next_type <= S_QUOTE))
		return (FALSE);
	if ((cur_type >= OR && cur_type <= PIPE) \
		&& (next_type >= OR && next_type <= PIPE))
		return (FALSE);
	return (TRUE);
}

static int	_is_valid_tokens(t_doubly_list *lst)
{
	t_doubly_node	*cur_node;
	t_doubly_node	*next_node;

	cur_node = lst->header.next;
	while (cur_node != lst->header.prev)
	{
		next_node = cur_node->next;
		if (_is_valid_next_token(cur_node, next_node) == FALSE)
		{
			syntax_error(cur_node->token->value);
			return (FALSE);
		}
		cur_node = cur_node->next;
	}
	if (!(cur_node->token->type >= CMD \
		&& cur_node->token->type <= S_QUOTE) \
		&& cur_node->token->type != BRACKET)
	{
		syntax_error(cur_node->token->value);
		return (FALSE);
	}
	return (TRUE);
}

// static int	_redir_here_doc_check(t_doubly_list *lst)
// {
// 	int				status;
// 	t_doubly_node	*here_doc;

// 	status = SUCCESS;
// 	here_doc = lst.header->next;
// 	g_var.hd_cnt = 0;
// 	while (here_doc)
// 	{
// 		if (here_doc->type == AND || here_doc->type == OR 
// 			|| here_doc->type == PIPE)
// 			g_var.hd_cnt++;
// 		if (here_doc->type == HERE_DOC)
// 		{
// 			here_doc->hd_num = g_var.hd_cnt;
// 			status = redir_here_doc_file(here_doc);
// 		}
// 		here_doc = here_doc->next;
// 	}
// 	if (!status)
// 		g_var.status = EXIT_FAILURE;
// 	return (status);
// }

// int	redir_here_doc_file(t_token *token)
// {
// 	pid_t	pid;
// 	char	*limiter;

// 	limiter = exec_rm_char(token->next);
// 	if (!limiter)
// 		return (FALSE);
// 	pid = fork();
// 	if (pid == -1)
// 		exit(EXIT_FAILURE);
// 	else if (pid == 0)
// 	{
// 		signal(SIGINT, sig_here_doc);
// 		redir_here_doc_child(limiter);
// 		exit(EXIT_FAILURE);
// 	}
// 	else
// 	{
// 		signal(SIGINT, SIG_IGN);
// 		waitpid(pid, &pid, 0);
// 		if (check_status(pid) == 130)
// 			return (FALSE);
// 	}
// 	return (SUCCESS);
// }

// static void	redir_here_doc_child(char *limiter)
// {
// 	int		hd_fd;
// 	char	*line;
// 	char	*hd_filename;

// 	signal(SIGINT, SIG_DFL);
// 	hd_filename = ft_strjoin(".here_doc", ft_itoa(g_var.hd_cnt));
// 	hd_fd = open(hd_filename, O_CREAT | O_RDWR | O_TRUNC, 0744);
// 	if (hd_fd == -1)
// 	{
// 		ft_perror(hd_filename, ": No such file or directory");
// 		exit(EXIT_FAILURE);
// 	}
// 	line = readline("> ");
// 	while (line && ft_strncmp(line, limiter, ft_strlen(limiter)) != 0)
// 	{
// 		if (ft_strchr(line, '$'))
// 			line = check_expand(line);
// 		ft_putstr_fd(line, hd_fd);
// 		ft_putstr_fd("\n", hd_fd);
// 		free(line);
// 		line = readline("> ");
// 	}
// 	close(hd_fd);
// 	exit(EXIT_SUCCESS);
// }

void	syntax(t_doubly_list *lst)
{
	t_doubly_node	*node;

	if (!lst || !lst->len)
		exit(1);
	node = lst->header.next;
	if (node->token->type == AND || node->token->type == OR || \
		node->token->type == PIPE)
	{
		syntax_error(node->token->value);
		return ;
	}
	if (!_is_valid_tokens(lst))
		return ;
	set_bintree(lst, lst->header.next);
}
