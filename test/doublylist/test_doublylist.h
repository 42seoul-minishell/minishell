#ifndef TEST_DOUBLYLIST_H
# define TEST_DOUBLYLIST_H

# include "../../include/minishell.h"
# include <string.h>
# include <errno.h>

/* in utils.c */
void	init_token(t_token *token, t_type type, char *value);
void	init_node(t_doubly_node *node, t_token *token);
void	init_lst(t_doubly_list *lst);

/* in test_utils.c */
int		test_is_list_empty(void);
int		test_is_not_list_empty(void);
int		test_find_node(char *str);
int		test_find_node_empty(char *str);

/* in test_create.c */
int		test_create_token(t_type type, char *value);
int		test_create_doubly_list(void);
int		test_create_doubly_node(t_type type, char *value);

/* in test_insert.c */
int		test_insert_node_empty(t_type type, char *value);
int		test_insert_node(t_type type, char *value);
int		test_insert_node_lst_null(void);
int		test_insert_node_node_null(void);
int		test_insert_node_by_index_empty(t_type type, char *value, size_t index);
int		test_insert_node_by_index(t_type type, char *value, size_t index);

/* in test_read.c */

/* in test_delete.c */


#endif