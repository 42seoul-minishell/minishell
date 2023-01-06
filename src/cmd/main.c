/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:36:05 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 13:36:06 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_save_history(char *input)
{
	if (input && *input)
		add_history(input);
}

static void	_sys_stdin(char **input_ptr)
{
	char	*prompt;

	set_signal();
	prompt = create_prompt();
	*input_ptr = readline(prompt);
	if (!*input_ptr)
	{
		printf("\033[1A");
		printf("\033[%tdC", ft_strlen(prompt));
		printf("exit\n");
		free(prompt);
		display_ctrlx_set(DISPLAY);
		exit(g_global.status);
	}
	free(prompt);
}

static void	_run(void)
{
	char	*input;

	while (1)
	{
		dup2(g_global.fd_stdin, STDIN_FILENO);
		dup2(g_global.fd_stdout, STDOUT_FILENO);
		input = NULL;
		_sys_stdin(&input);
		if (is_only_space(input))
			continue ;
		_save_history(input);
		if (parser(input) == TRUE)
		{
			g_global.status = 0;
			set_heredoc_signal();
			set_heredoc(g_global.tree->root);
			if (g_global.status == 0)
			{
				set_execute_signal();
				display_ctrlx_set(DISPLAY);
				executor(g_global.tree->root, 0, 1, 0);
				wait_child();
				free(input);
				reset_global();
				display_ctrlx_set(NODISPLAY);
			}
			else
			{
				clear_bintree(g_global.tree->root);
				g_global.tree->root = NULL;
			}
		}
	}
}

/* 삭제 예정 */
void	check_leak(void)
{
	system("leaks minishell");
}

int	main(int argc, char **argv, char **envp)
{
	t_hashtable	*table;
	t_bintree	*tree;

	// atexit(check_leak);
	g_global.envp_arr = envp;
	table = parse_env_to_hashtable(envp);
	tree = create_bintree();
	create_global(tree, table);
	if (argc == 2)
	{
		if (parser(argv[1]) == TRUE)
		{
			set_execute_signal();
			display_ctrlx_set(NODISPLAY);
			set_heredoc(g_global.tree->root);
			display_ctrlx_set(DISPLAY);
			executor(g_global.tree->root, 0, 1, 0);
			wait_child();
			reset_global();
			delete_table(g_global.envp);
			return (g_global.status);
		}
		return (1);
	}
	display_ctrlx_set(NODISPLAY);
	_run();
	return (0);
}
