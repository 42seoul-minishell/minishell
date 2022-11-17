/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:17:33 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/17 21:36:16 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minishell.h"

void	syntax(t_doubly_list *lst)
{
	if (check_syntax_error(info.h_token) == SUCCESS && \
		redir_here_doc_check(&info) == SUCCESS)
	{
		info.r_node = create_btree_node(info.h_token);
		set_btree_node(&(info.r_node));
		// treeprint(info.r_node, 0);
		ft_display_ctrlx_set(DISPLAY);
		status = execution(&info);
		ft_display_ctrlx_set(NODISPLAY);
		free(cmd_line);
	}
	else
		delete_token(info.h_token);
	redir_unlink();
}
