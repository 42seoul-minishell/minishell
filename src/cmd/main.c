/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:58:16 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/01 12:53:13 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	save_history(char *input)
{
	if (input && *input)
		add_history(input);
}

static void	sys_stdin(char **input)
{
	char	*prompt;

	prompt = create_prompt();
	*input = readline(prompt);
	free(prompt);
}

static void	run(void)
{
	char	*input;

	while (1)
	{
		input = NULL;
		sys_stdin(&input);
	}
}

int	main(void)
{
	t_hashtable	*table;
	char		*pwd;

	table = parse_env_to_hashtable(environ);
	display_hashtable(table);
	delete_table(table);
	run();
	system("leaks minishell");
	return (0);
}
