/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:13:05 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/16 15:13:32 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./base.h"

/* token type enumerate */
typedef enum e_type
{
	T_NULL = 1,
	T_CMD,
	T_PIPE,
	T_REDIRECT,
	T_DOUBLE_QUOTES,
	T_BRACKET,
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

/* hashtable item structure */
typedef struct s_ht_item
{
	char					*key;
	char					*value;
	struct s_ht_item		*next;
}	t_ht_item;

/* hashtable structure */
typedef struct s_hashtable
{
	t_ht_item		**items;
	size_t			size;
	size_t			count;
}	t_hashtable;

/* structure includes all other structures */
typedef struct s_global
{
	t_hashtable		*envp;
	t_doubly_list	*lst;
	t_btree			*tree;
	int				status;
}	t_global;

/* bintree node */
typedef struct s_bintree_node
{
	int					id;
	t_token				*token;
	struct s_bintree_node	*lc;
	struct s_bintree_node	*rc;
}	t_bintree_node;

/* bintree structure */
typedef struct s_bintree
{
	t_bintree_node	*root;
}	t_bintree;

#endif