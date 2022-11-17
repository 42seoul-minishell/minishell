/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bintree.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:27:28 by bolee             #+#    #+#             */
/*   Updated: 2022/11/17 17:02:12 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_bintree_H
#define TEST_bintree_H

#include "../../include/minishell.h"
#include <string.h>

/* in utils.c */
void init_token(t_token *token, t_tnType type, char *value);
void init_bintree_node(t_bintree_node *node, int id);
void init_bintree(t_bintree *bintree);

/* in test_create.c */
int test_create_bintree(void);
int test_create_bintree_node(void);

/* in test_insert.c */
int test_insert_lc_node_null(void);
int test_insert_lc_node(void);
int test_insert_rc_node_null(void);
int test_insert_rc_node(void);

/* in test_read.c */
int test_get_bintree_node_by_id_null(int id);
int test_get_bintree_node_by_id(int id);

/* in test_delete.c */
int test_delete_bintree_node_lc_null_node(void);
int test_delete_bintree_node_lc_null(void);
int test_delete_bintree_node_lc(void);
int test_delete_bintree_node_rc_null_node(void);
int test_delete_bintree_node_rc_null(void);
int test_delete_bintree_node_rc(void);
void test_delete_bintree_node_chlid(void);

#endif
