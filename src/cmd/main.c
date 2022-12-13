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

#include "../../include/minishell.h"

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
		exit_error("\033[31mError: readline(): Failed to read line\n\033[0m");
	free(prompt);
}

static void	_run(void)
{
	char	*input;
	char	*temp;

	while (1)
	{
		dup2(g_global->fd_stdin, STDIN_FILENO);
		dup2(g_global->fd_stdout, STDOUT_FILENO);
		input = NULL;
		_sys_stdin(&input);
		_save_history(input);
		temp = ft_strdup(input);
		parser(temp);
		// executor(temp);
		free(input);
		free(temp);
		break;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_hashtable	*table;
	t_bintree	*tree;

	printf("ac = %d\n", ac);
	*av = NULL;
	setting_signal();
	table = parse_env_to_hashtable(envp);
	tree = create_bintree();
	g_global = create_global(tree, table);
	_run();
	return (0);
}
