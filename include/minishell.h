/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:08:00 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/02 14:46:37 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./builtin.h"
# include "./core.h"
# include "./doublylist.h"
# include "./executor.h"
# include "./hashtable.h"
# include "./token.h"
# include "./struct.h"
# include "./base.h"

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

/* in ../src/internal/btree/ */
/* insert.c */
int				insert_lc_node(t_btree_node *parent, t_token *token);
int				insert_rc_node(t_btree_node *parent, t_token *token);
/* create.c */
t_btree			*create_btree(void);
t_btree_node	*create_btree_node(t_token *token);
/* delete.c */
void			delete_btree_node_child(t_btree_node *parent);
int				delete_btree_node_lc(t_btree_node *parent);
int				delete_btree_node_rc(t_btree_node *parent);
/* utils.c */
void			display_btree_node_child(t_btree_node *node);
void			display_btree_node_by_preorder(t_btree_node *node);
void			display_btree_by_preorder(t_btree *btree);
/* read.c */
t_btree_node	*get_btree_node_by_id(t_btree_node *node, int id);

#endif
