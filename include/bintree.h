/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:52:25 by bolee             #+#    #+#             */
/*   Updated: 2022/11/17 17:09:02 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINTREE_H
# define BINTREE_H

# include "./struct.h"

/* in ../src/internal/bintree/ */
/* insert.c */
int				insert_lc_node(t_bintree_node *parent, \
					t_token *token, t_tnType type);
int				insert_rc_node(t_bintree_node *parent, \
					t_token *token, t_tnType type);

/* create.c */
t_bintree		*create_bintree(void);
t_bintree_node	*create_bintree_node(t_token *token, t_tnType type);

/* delete.c */
void			delete_bintree_node_child(t_bintree_node *parent);
int				delete_bintree_node_lc(t_bintree_node *parent);
int				delete_bintree_node_rc(t_bintree_node *parent);

/* utils.c */
void			display_bintree_node_child(t_bintree_node *node);
void			display_bintree_node_by_preorder(t_bintree_node *node);
void			display_bintree_by_preorder(t_bintree *bintree);
int				clear_bintree_node(t_bintree_node *root);

/* read.c */
t_bintree_node	*get_bintree_node_by_id(t_bintree_node *node, int id);

#endif