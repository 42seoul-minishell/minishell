#ifndef TEST_BTREE_H
#define TEST_BTREE_H

#include "../../include/minishell.h"
#include <string.h>

/* in utils.c */
void init_token(t_token *token, t_type type, char *value);
void init_btree_node(t_btree_node *node, int id);
void init_btree(t_btree *btree);

/* in test_create.c */
int test_create_btree(void);
int test_create_btree_node(void);

/* in test_insert.c */
int test_insert_lc_node_null(void);
int test_insert_lc_node(void);
int test_insert_rc_node_null(void);
int test_insert_rc_node(void);

/* in test_read.c */
int test_get_btree_node_by_id_null(int id);
int test_get_btree_node_by_id(int id);

/* in test_delete.c */
int test_delete_btree_node_lc_null_node(void);
int test_delete_btree_node_lc_null(void);
int test_delete_btree_node_lc(void);
int test_delete_btree_node_rc_null_node(void);
int test_delete_btree_node_rc_null(void);
int test_delete_btree_node_rc(void);
void test_delete_btree_node_chlid(void);

#endif