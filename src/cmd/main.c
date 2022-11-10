/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:58:16 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/10 20:51:12 by mingkim          ###   ########.fr       */
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
	char	*input;
	char	*temp;

	while (1)
	{
		input = NULL;
		sys_stdin(&input);
		save_history(input);
		temp = ft_strdup(input);
		tokenizer(lst, temp);
		lexer(lst, temp);
		free(input);
		free(temp);
		release_doubly_list(lst);
		break ;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_hashtable		*table;
	t_doubly_list	*lst;

	ac = 0;
	av = NULL;
	setting_signal();
	table = parse_env_to_hashtable(envp);
	lst = create_doubly_list();
	run(lst);
	system("leaks minishell");
	return (0);
}
