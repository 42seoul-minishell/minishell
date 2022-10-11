#include "test_btree.h"

static void _should_pass(int rv)
{
	if (rv == TRUE)
		printf("\033[92m✔\033[0m");
	else
		printf("\033[31m✗\033[0m");
}

static void _should_fail(int rv)
{
	if (rv == TRUE)
		printf("\033[31m✗\033[0m");
	else
		printf("\033[92m✔\033[0m");
}

int main(void)
{
	printf("\n=======TEST creat.c in btree=======\n");

	printf("create_btree(): ");
	_should_pass(test_create_btree());
	putchar('\n');

	printf("create_btree_node(): ");
	_should_pass(test_create_btree_node());
	putchar('\n');

	printf("\n=======TEST insert.c in btree=======\n");

	printf("insert_lc_node(): ");
	_should_fail(test_insert_lc_node_null());
	_should_pass(test_insert_lc_node());
	putchar('\n');

	printf("insert_rc_node(): ");
	_should_fail(test_insert_rc_node_null());
	_should_pass(test_insert_rc_node());
	putchar('\n');

	printf("\n=======TEST read.c in btree=======\n");

	printf("get_btree_node_by_id(): ");
	_should_pass(test_get_btree_node_by_id_null(0));
	_should_pass(test_get_btree_node_by_id_null(-1));
	_should_pass(test_get_btree_node_by_id_null(1));
	_should_pass(test_get_btree_node_by_id_null(7));

	_should_pass(test_get_btree_node_by_id(1)); //
	_should_pass(test_get_btree_node_by_id(2)); //
	_should_pass(test_get_btree_node_by_id(3));
	_should_pass(test_get_btree_node_by_id(4));
	_should_pass(test_get_btree_node_by_id(5));
	_should_pass(test_get_btree_node_by_id(6));
	_should_pass(test_get_btree_node_by_id(7));
	_should_pass(test_get_btree_node_by_id(8));

	_should_fail(test_get_btree_node_by_id(10));
	_should_fail(test_get_btree_node_by_id(-1));
	_should_fail(test_get_btree_node_by_id(0));
	putchar('\n');

	printf("\n=======TEST delete.c in btree=======\n");

	printf("delete_btree_node_lc(): ");
	_should_fail(test_delete_btree_node_lc_null_node());
	_should_fail(test_delete_btree_node_lc_null());
	_should_pass(test_delete_btree_node_lc());
	putchar('\n');

	printf("delete_btree_node_rc(): ");
	_should_fail(test_delete_btree_node_lc_null_node());
	_should_fail(test_delete_btree_node_lc_null());
	_should_pass(test_delete_btree_node_lc());
	putchar('\n');

	printf("delete_btree_node_child()");
	test_delete_btree_node_chlid();

	system("leaks testBtree | grep 'leaks for '");

	return (0);
}