/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:58:14 by bolee             #+#    #+#             */
/*   Updated: 2022/09/21 23:35:38 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "Syntax.h"

/* node structure */
typedef struct	s_node
{
    t_token         *token;
    struct s_node	*lc;
    struct s_node   *rc;
}	t_node;

/* tree structure */
typedef struct	s_tree
{
	t_node	*root;
}	t_tree;

/* Tree create related functions in Tree.c */
t_node  *create_node(t_token *token);
t_tree	*create_tree();

/* Tree update or insert related functions in Tree.c */
void	update_node_data(t_node *node, char *str);
void	insert_lc_node(t_node *parent, t_token *token);
void	insert_rc_node(t_node *parent, t_token *token);

/* Tree print related functions in Tree.c */
void	print_chlid(t_node *node);
void	print_node_by_preorder(t_node *node);
void	preorder_tree(t_tree *tree);

/* Tree delete related functions in Tree.c */
void	delete_all_child(t_node *parent);
void	delete_lc(t_node *parent);
void	delete_rc(t_node *parent);

/* in Parser.c */
void    add(t_tree  **tree, t_token *token);
t_tree  *parsing(t_tokens *tokens);

#endif
