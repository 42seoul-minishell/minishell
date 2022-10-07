#include "test_doublylist.h"

static void	_should_display_pass(int rv)
{
	if (rv == TRUE)
		printf("\033[92m✔\033[0m");
	else
		printf("\033[31m✗\033[0m");
}

static void	_should_display_fail(int rv)
{
	if (rv == TRUE)
		printf("\033[31m✗\033[0m");
	else
		printf("\033[92m✔\033[0m");
}

int	main(void)
{
	printf("\n=======TEST utils.c in doublylist=======\n");

	printf("is_list_empty(): ");
	_should_display_pass(test_is_list_empty());
	_should_display_pass(test_is_not_list_empty());
	putchar('\n');

	printf("find_node(): ");
	_should_display_pass(test_find_node_empty("TEST00"));
	_should_display_pass(test_find_node_empty("TEST01"));
	_should_display_pass(test_find_node_empty("TEST02"));

	_should_display_pass(test_find_node("TEST00"));
	_should_display_pass(test_find_node("TEST01"));
	_should_display_pass(test_find_node("TEST02"));
	_should_display_fail(test_find_node("TEST03"));
	_should_display_fail(test_find_node("TEST04"));
	_should_display_fail(test_find_node("TEST05"));
	putchar('\n');

	printf("\n=======TEST creat.c in doublylist=======\n");

	printf("create_token(): ");
	_should_display_pass(test_create_token(1, "TEST"));
	_should_display_pass(test_create_token(2, "TEST"));
	_should_display_pass(test_create_token(3, "TEST"));
	_should_display_pass(test_create_token(4, "TEST"));
	_should_display_pass(test_create_token(5, "TEST"));
	_should_display_fail(test_create_token(6, "TEST"));
	putchar('\n');

	printf("create_doubly_list(): ");
	_should_display_pass(test_create_doubly_list());
	putchar('\n');

	printf("create_doubly_node(): ");
	_should_display_pass(test_create_doubly_node(1, "TEST"));
	_should_display_pass(test_create_doubly_node(2, "TEST"));
	_should_display_pass(test_create_doubly_node(3, "TEST"));
	_should_display_pass(test_create_doubly_node(4, "TEST"));
	_should_display_pass(test_create_doubly_node(5, "TEST"));
	putchar('\n');

	printf("\n=======TEST insert.c in doublylist=======\n");
	printf("insert_node(): ");
	_should_display_pass(test_insert_node_empty(1, "TEST"));
	_should_display_pass(test_insert_node_empty(2, "TEST"));
	_should_display_pass(test_insert_node_empty(3, "TEST"));
	_should_display_pass(test_insert_node_empty(4, "TEST"));
	_should_display_pass(test_insert_node_empty(5, "TEST"));

	_should_display_pass(test_insert_node(1, "TEST"));
	_should_display_pass(test_insert_node(2, "TEST"));
	_should_display_pass(test_insert_node(3, "TEST"));
	_should_display_pass(test_insert_node(4, "TEST"));
	_should_display_pass(test_insert_node(5, "TEST"));

	_should_display_pass(test_insert_node_lst_null());
	_should_display_pass(test_insert_node_node_null());
	putchar('\n');

	printf("insert_node_by_index(): ");
	_should_display_pass(test_insert_node_by_index_empty(1, "TEST", 0));
	_should_display_fail(test_insert_node_by_index_empty(1, "TEST", 1));
	_should_display_fail(test_insert_node_by_index_empty(1, "TEST", 7));
	_should_display_fail(test_insert_node_by_index_empty(1, "TEST", 100));

	_should_display_fail(test_insert_node_by_index(1, "TEST", 0));
	_should_display_pass(test_insert_node_by_index(1, "TEST", 1));
	_should_display_pass(test_insert_node_by_index(1, "TEST", 7));
	_should_display_pass(test_insert_node_by_index(1, "TEST", 100));
	putchar('\n');

	printf("\n=======TEST read.c in doublylist=======\n");

	printf("get_node_by_index(): ");
	putchar('\n');


	printf("\n=======TEST delete.c in doublylist=======\n");

	printf("delete_one(): ");
	putchar('\n');

	printf("find_delete(): ");
	putchar('\n');

	system("leaks testDoublyList | grep 'leaks for '");
	return (0);
}
