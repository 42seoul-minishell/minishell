/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:32:16 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 13:32:19 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINTREE_H
#define BINTREE_H

#include "struct.h"

/* in ../src/internal/bintree/ */
/* insert.c */
int insert_lc_node(t_bintree_node *parent, t_list *token_list, t_tnType type);
int insert_rc_node(t_bintree_node *parent, t_list *token_list, t_tnType type);

/* create.c */
t_bintree	*create_bintree(void);
t_bintree_node	*create_bintree_node(t_list *token_list, t_tnType type);

/* delete.c */
void		delete_bintree_node_child(t_bintree_node *parent);
int		delete_bintree_node_lc(t_bintree_node *parent);
int		delete_bintree_node_rc(t_bintree_node *parent);
int		clear_bintree_node(t_bintree_node *root);

/* utils.c */
void		print_token_lst(t_list *token_lst);
void		display_bintree_node_child(t_bintree_node *node);
void		display_bintree_by_2D(t_bintree *bintree);

/* read.c */
t_bintree_node	*get_last_rc_node(t_bintree_node *node);
t_bintree_node	*get_last_lc_node(t_bintree_node *node);

#endif
