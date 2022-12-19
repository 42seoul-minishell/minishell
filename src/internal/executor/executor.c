/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:19:58 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:19:59 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* execute by preorder and inorder */
void	executor(t_bintree_node	*root)
{
	// if (root->type == TN_OR)
	// 	execute_or(root);
	// else if (root->type == TN_AND)
	// 	execute_and(root);
	// else if (root->type == TN_PIPE)
	// 	execute_pipe(root);
	// else if (root->type == TN_RDIR)
	// 	execute_redirect(root);
	// else if (root->type == TN_BRACKET)
	// 	execute_bracket(root);
	// else
		execute_command(root);
}

int	serve_status(char *cmd)
{
	int	status;

	printf("cmd = %s\n", cmd);
	status = EXIT_SUCCESS;
	return (status);
}
