/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:08:00 by mingkim           #+#    #+#             */
/*   Updated: 2022/10/07 14:08:54 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <signal.h>
# include <dirent.h>
# include "libft/libft.h"

# define TRUE	1
# define FALSE	0

typedef enum e_type
{
	T_NULL = 1,
	T_WORD,
	T_PIPE,
	T_REDIRECT,
	T_DOUBLE_QUOTES,
}	t_type;

/* token structure */
typedef struct s_token
{
	t_type	type;
	char	*value;
}	t_token;

/* node of double linked list */
typedef struct s_doubly_node
{
	t_token					*token;
	struct s_doubly_node	*prev;
	struct s_doubly_node	*next;
}	t_doubly_node;

/* double linked list */
typedef struct s_doubly_list
{
	t_doubly_node	header;
	size_t			len;
}	t_doubly_list;

/* btree node */
typedef struct s_btree_node
{
	int					id;
	t_token				*token;
	struct s_btree_node	*lc;
	struct s_btree_node	*rc;
}	t_btree_node;

/* btree structure */
typedef struct s_btree
{
	t_btree_node	*root;
}	t_btree;

/* in ../src/internal/doublylist/utils.c */
int				is_list_empty(t_doubly_list *lst);
void			display_list(t_doubly_list *lst);
t_type			switch_type(t_type type);
t_doubly_node	*find_node(t_doubly_list *lst, char *str);

/* in ../src/internal/doublylist/delete.c */
void			delete_one(t_doubly_node *node);
void			find_delete(t_doubly_list *lst, char *str);
void			release_list(t_doubly_list *lst);

/* in ../src/internal/doublylist/create.c */
t_token			*create_token(t_type type, char *value);
t_doubly_list	*create_doubly_list(void);
t_doubly_node	*create_doubly_node(t_token *token);

/* in ../src/internal/doublylist/insert.c */
int				insert_node(t_doubly_list *lst, t_doubly_node *node);
int				insert_node_by_index(t_doubly_list *lst, \
										t_doubly_node *node, size_t index);


int				insert_lc_node(t_btree_node *parent, t_token *token);
int				insert_rc_node(t_btree_node *parent, t_token *token);

t_btree			*create_btree(void);
t_btree_node	*create_node(t_token *token);

void			delete_child(t_btree_node *parent);
int				delete_left_child(t_btree_node *parent);
int				delete_right_child(t_btree_node *parent);

void			display_child(t_btree_node *node);
void			display_node_by_preorder(t_btree_node *node);
void			display_btree_by_preorder(t_btree *btree);
#endif