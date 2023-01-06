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
		input = NULL;
		_sys_stdin(&input);
		if (is_only_space(input))
			continue ;
		_save_history(input);
		if (parser(input) == TRUE)
			execution_main();
		free(input);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_hashtable	*table;
	t_bintree	*tree;

	g_global.envp_arr = envp;
	table = parse_env_to_hashtable(envp);
	tree = create_bintree();
	create_global(tree, table);
	if (argc == 2)
	{
		if (parser(argv[1]) == TRUE)
		{
			execution_sub();
			return (g_global.status);
		}
		return (1);
	}
	_run();
	return (0);
}
