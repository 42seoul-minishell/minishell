/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:58:16 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/02 15:10:07 by mingkim          ###   ########.fr       */
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

static void	run(t_doubly_list *lst)
{
	char			*input;

	while (1)
	{
		input = NULL;
		sys_stdin(&input);
		save_history(input);
		// tokenizing
		tokenizing(lst, ft_strdup(input));
		display_list(lst);
		// parsing
		// execute
		// free
		free(input);
	}
}

int	main(void)
{
	t_hashtable		*table;
	t_doubly_list	*lst;

	setting_signal();
	table = parse_env_to_hashtable(environ);
	lst = create_doubly_list();
	run(lst);
	system("leaks minishell");
	return (0);
}
