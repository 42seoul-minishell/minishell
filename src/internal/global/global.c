/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:15:34 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/16 17:35:26 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_global	*create_global(t_bintree *tree, t_hashtable *envp)
{
	t_global	*global;

	global = (t_global *)sp_malloc(sizeof(t_global));
	global->envp = envp;
	global->status = 0;
	global->fd_stdin = dup(STDIN_FILENO);
	global->fd_stdout = dup(STDOUT_FILENO);
	global->tree = tree;
	if (tcgetattr(STDIN_FILENO, &(global->display_set)) == ERROR)
		exit_on_error("minsh: tcgetattr");
	if (tcgetattr(STDIN_FILENO, &(global->nodisplay_set)) == ERROR)
		exit_on_error("minsh: tcgetattr");
	global->nodisplay_set.c_lflag &= ~ECHOCTL;
	ft_display_ctrlx_set(NODISPLAY);
	return (global);
}
