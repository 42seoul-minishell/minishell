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

t_global	g_global;

static void	_save_history(char *input)
{
	if (input && *input)
		add_history(input);
}

static void	_sys_stdin(char **input_ptr)
{
	char	*prompt;

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
		_save_history(input);
		parser(input);
		set_heredoc(g_global.tree->root);
		executor(g_global.tree->root, 0, 1, 0);
		free(input);
		clear_bintree(g_global.tree->root);
		g_global.tree->root = NULL;
	}
}

void	check_leak(void)
{
	system("leaks minishell");
}

int	main(int ac, char **av, char **envp)
{
	t_hashtable	*table;
	t_bintree	*tree;

	// atexit(check_leak);
	printf("ac = %d\n", ac);
	*av = NULL;
	set_signal();
	g_global.envp_arr = envp;
	table = parse_env_to_hashtable(envp);
	tree = create_bintree();
	create_global(tree, table);
	_run();
	return (0);
}
