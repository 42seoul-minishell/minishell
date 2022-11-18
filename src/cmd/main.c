/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:58:16 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/18 17:18:17 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	save_history(char *input)
{
	if (input && *input)
		add_history(input);
}

static void	sys_stdin(char **input_ptr)
{
	char	*prompt;

	prompt = create_prompt();
	*input_ptr = readline(prompt);
	if (!*input_ptr)
	{
		printf("\033[1A");
		printf("\033[%tdC", ft_strlen(prompt));
		printf("exit\n");
		exit(0);
	}
	free(prompt);
}

static void	run(void)
{
	char	*input;
	char	*temp;

	while (1)
	{
		dup2(g_global->fd_stdin, STDIN_FILENO);
		dup2(g_global->fd_stdout, STDOUT_FILENO);
		input = NULL;
		sys_stdin(&input);
		save_history(input);
		temp = ft_strdup(input);
		parser(temp);
		executor(temp);
		free(input);
		free(temp);
		break ;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_hashtable	*table;
	t_bintree	*tree;

	ac = 0;
	av = NULL;
	setting_signal();
	table = parse_env_to_hashtable(envp);
	tree = create_bintree();
	g_global = create_global(tree, table);
	run();
	return (0);
}
