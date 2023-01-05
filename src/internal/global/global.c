/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:20:46 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 14:20:47 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_global(t_bintree *tree, t_hashtable *envp)
{
	g_global.envp = envp;
	g_global.origin_path = search(g_global.envp, "PWD");
	g_global.status = 0;
	g_global.fd_stdin = dup(STDIN_FILENO);
	g_global.fd_stdout = dup(STDOUT_FILENO);
	g_global.tree = tree;
	if (tcgetattr(STDIN_FILENO, &(g_global.display_set)) == ERROR)
		exit_error("Error: tcgetattr()");
	if (tcgetattr(STDIN_FILENO, &(g_global.nodisplay_set)) == ERROR)
		exit_error("Error: tcgetattr()");
	g_global.nodisplay_set.c_lflag &= ~ECHOCTL;
	display_ctrlx_set(NODISPLAY);
}
