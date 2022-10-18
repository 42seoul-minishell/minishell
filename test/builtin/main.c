/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:32:05 by mingkim           #+#    #+#             */
/*   Updated: 2022/10/18 12:58:54 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_builtin.h"

static void	_should_pass(int rv)
{
	if (rv == TRUE)
		printf("\033[92m✔\033[0m");
	else
		printf("\033[31m✗\033[0m");
}

static void	_should_fail(int rv)
{
	if (rv == TRUE)
		printf("\033[31m✗\033[0m");
	else
		printf("\033[92m✔\033[0m");
}

int	main(void)
{
	char	*path;
	char	*buf;
	char	*answer;

	// ===== TEST FOR CD SUCCESS CASE =====

	// get current directory
	path = getcwd(NULL, 9999);
	// make new directory
	mkdir("test_cd_dir", 0755);
	// change directory
	builtin_cd("test_cd_dir/");
	// get current directory
	buf = getcwd(NULL, 9999);
	answer = ft_strjoin(path, "/test_cd_dir");

	// test 
	printf("builtin_cd success : ");
	if (ft_strncmp(answer, buf, ft_strlen(buf)) == 0)
		_should_pass(TRUE);
	builtin_cd("../");
	putchar('\n');

	printf("remove directory: ");
	_should_pass(rmdir(buf) == 0 ? TRUE : FALSE);
	putchar('\n');
	// free pointers
	free(path);
	free(buf);
	free(answer);

	// ===== TEST FOR CD FAIL CASE =====

	// get current directory
	path = getcwd(NULL, 9999);
	// move to directory does not exist.
	printf("move to directory does not exist : ");
	_should_fail(builtin_cd("test_cd_dir/"));
	putchar('\n');

	// free pointers
	free(path);

	// ===== TEST FOR ECHO WITH NO NEW LINE OPTIONS =====
	builtin_echo("test for echo\n", 1, 0);

	// ===== TEST FOR ECHO WITH NEW LINE OPTION =====
	builtin_echo("test for echo\n", 1, 1);

	// ===== TEST FOR PWD =====
	builtin_pwd();
	
	// ===== TEST FOR PWD WITH NULL ERROR =====

	// LEAK CHECK
	system("leaks testBuiltin | grep LEAK");
	system("leaks testBuiltin | grep leaked");
	return (0);
}
